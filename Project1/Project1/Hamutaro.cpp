//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Hamutaro.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
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

//�C�j�V�����C�Y
void CObjNezumi::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[��������

	flag = false;
	Bflag = false;
	m_return = false;

	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	Dimax = 32;

	hamstop = false;
	hamnam=0;

	speed = 2;

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�������o��

	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ITEM, OBJ_HAMUTARO, 1);
}
//�A�N�V����
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
		}

		else
		{
			m_x += -speed;
		}
	}

	//�}�b�v�����m�F����
	if(m_return==false)
		m_return = mapsarch(m_x,m_y,m_posture);

	//��莞�Ԉړ�����ƋA���Ă���
	if (m_x > b_x + 300 || m_x + 300 < b_x ||
		m_hit_left == true || m_hit_right==true)
	{
		if (m_return == false) {
			m_return = true;
			speed = -speed;
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
//�h���[
void CObjNezumi::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll + 32.0f + (32.0f - Dimax);
	dst.m_left = m_x + m_scroll + 32.0f + (32.0f - Dimax);
	dst.m_right = dst.m_left + Dimax;
	dst.m_bottom = dst.m_top + Dimax;

	Draw::Draw(0, &src, &dst, c, 0.0f);
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

	return map_data[mp_y][mp_x];
}
