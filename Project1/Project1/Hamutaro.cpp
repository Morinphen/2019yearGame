//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hamutaro.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjNezumi::CObjNezumi(int x, int y, int muki)
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	memcpy(map_data, scroll->m_map, sizeof(int)*(46 * 100));

	m_x = x - m_scroll;
	m_y = y - l_scroll;

	m_vx = 0.0f;
	m_vy = 0.0f;

	b_x = m_x;
	b_y = m_y;
	m_posture = -muki;
}

//イニシャライズ
void CObjNezumi::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	flag = false;
	Bflag = false;
	m_return = false;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	Dimax = 32;

	hamstop = false;
	naki = false;
	hamnam=0;

	speed = 2;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_HAMUTARO, 1);
}
//アクション
void CObjNezumi::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	pb->BlockHit(&m_x, &m_y, false,false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
		&m_vx, &m_vy
	);

	if (hamstop == false)
	{
		if (m_posture == 0)
		{
			m_x += speed;
			m_ani_time += 1;
			if (m_return == false)
			{
				a_pos = true;
			}

		}

		else if(m_posture==-1)
		{
			m_x += -speed;
			m_ani_time += 1;
			if (m_return == false)
			{
				a_pos = false;
			}
		}
		else
		{
			m_ani_frame = 1;
			m_ani_time = 0;
		}

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}

		if (m_ani_frame == 4)
		{
			m_ani_frame = 0;
			if (naki == true)
			{
				naki = false;
				Audio::Start(9);
			}
			else
			{
				naki = true;
			}
		}

	}

	//マップ情報を確認する
	if(m_return==false)
		m_return = mapsarch(m_x,m_y,m_posture);

	//一定時間移動すると帰ってくる
	if (m_x > b_x + 300 || m_x + 300 < b_x ||
		m_hit_left == true || m_hit_right==true)
	{
		if (m_return == false) {
			m_return = true;
			speed = -speed;
			if (a_pos == true)
			{
				a_pos = false;
			}
			else
			{
				a_pos = true;
			}
		}

	}

	if (hit->CheckObjNameHit(OBJ_NEZUANA) != nullptr)
	{
		hamstop = true;
	}

	else if (b_x + 10 >= m_x && m_return == true &&
		b_x - 10 <= m_x && m_return == true)
	{
		h->HamuSetUP(false);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	else if (h->Ninzyutu == true)
	{
		h->HamuSetUP(false);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (hamstop == true)
	{
		Dimax--;
		if (Dimax == 0) {
			hamnam = mapplace(m_x, m_y,m_posture);
			CObjNezuana* ne = (CObjNezuana*)Objs::GetObj(hamnam);
			ne->SetFlag(true);
			h->HamuSetUP(false);
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
	else {
		hit->SetPos(m_x + m_scroll + 32.0f, m_y + l_scroll + 32.0f);
	}
}
//ドロー
void CObjNezumi::Draw()
{
	int AniData[4] =
	{
		0,1,0,1
	};
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	if (a_pos==true)
	{
		src.m_top = 0.0f;
		src.m_left = 24.0f*AniData[m_ani_frame] - 24;
		src.m_right = 24.0f*AniData[m_ani_frame];
		src.m_bottom = 21.0f;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 24.0f*AniData[m_ani_frame];
		src.m_right = 24.0f*AniData[m_ani_frame]-24;
		src.m_bottom = 21.0f;
	}

	dst.m_top = m_y + l_scroll + 32.0f + (32.0f - Dimax);
	dst.m_left = m_x + m_scroll + 32.0f + (32.0f - Dimax);
	dst.m_right = dst.m_left + Dimax;
	dst.m_bottom = dst.m_top + Dimax;
	Draw::Draw(34, &src, &dst, c, 0.0f);
}

bool CObjNezumi::mapsarch(int x, int y, int muki)
{
	bool flag;
	int mp_x, mp_y;

	mp_x = 1 + (muki * 1);
	mp_y = 2;

	for (; x > 64.0;)
	{
		mp_x++;
		x -= 64;
	}

	for (; y > 64.0;)
	{
		mp_y++;
		y -= 64;
	}

	if (map_data[mp_y][mp_x] == 0)
	{
		flag = true;
		if (a_pos == true)
		{
			a_pos = false;
		}
		else
		{
			a_pos = true;
		}
		speed = -speed;
	}
	else
	{
		flag = false;
	}
	return flag;
}

int CObjNezumi::mapplace(int x, int y, int muki)
{
	bool flag;
	int mp_x, mp_y;

	int rflag;//送る値
	bool stop = false;

	mp_x = 1 + (muki * 1);
	mp_y = 1;

	for (; x > 64.0;)
	{
		mp_x++;
		x -= 64;
	}

	for (; y > 64.0;)
	{
		mp_y++;
		y -= 64;
	}

	for (int i = mp_x - 3; i < mp_x+3; i++)
	{
		if (stop == true)
			break;
		for (int j = mp_y - 3; j < mp_y+3; j++)
		{
			if (map_data[j][i] == 57 || map_data[j][i] == 58)
			{
				rflag = map_data[j][i];
				stop = true;
				break;
			}
		}
	}

	return rflag;
}
