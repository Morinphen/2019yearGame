//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Nagenawa.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjNagenawa::CObjNagenawa(int x, int y, int a, float vx, float vy)
{
	m_x = x;
	m_y = y - 10;

	b_x = x;
	b_y = y - 10;;

	m_vx = vx / 50;

	m_vy = vy / 40;

	m_muki = a;
}

//イニシャライズ
void CObjNagenawa::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	m_vy = -m_vy * 2;
	grabty = m_vy;

	Nawa = 0;
	r = 0;

	//m_vy = -15;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_NAGENAWA, 1);
}
//アクション
void CObjNagenawa::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	float aa, bb;
	//ブロックの当たり判定を行う当たれば消滅させる
	pb->BlockHit(&m_x, &m_y, true, false,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
		&m_vx, &m_vy
	);

	bool Mode;
	Mode = h->GetChange();

	//縄ブロックに当たった時、縄を消滅させ、主人公を移動させる
	if (hit->CheckObjNameHit(OBJ_NBLOCK) != nullptr)
	{
		Audio::Start(12);
		float a = abs(m_y - h->GetY());
		h->ReSetN(false);
		h->NawaIdo(true);
		h->SetNX(m_x - h->GetX());
		h->SetNY(a - 20);
		r = Angle();
		h->SetAngle(r);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	else if (m_hit_up == true ||
		m_hit_down == true ||
		m_hit_left == true ||
		m_hit_right == true ||
		m_y > 700.0f)
	{
		Audio::Start(12);
		float a = abs(m_y - h->GetY());
		h->ReSetN(false);
		h->Setstop(false);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	///////////////////////////////////////////////////////

	//縄が出現しているときに一定の行動を行った場合、消滅させる
	else if (h->Ninzyutu == true || Mode == true)
	{
		h->ReSetN(false);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	m_x += m_vx*m_muki;

	//重力
	m_vy += (-grabty / 3) / 16.0f;

	m_y += m_vy;


	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	hit->SetPos(m_x, m_y);
}
//ドロー
void CObjNagenawa::Draw()
{
	//縄部分の描画
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	CObjScroll* s = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	//vectorの作成
	float vx = (m_x)-h->GetX();
	float vy = (m_y)-h->GetY();

	//角度を求める
	float r = atan2(-vy, vx);
	r = r * 180 / 3.14;

	if (r < 0)
		r = 360.0f - abs(r);

	float ar = atan2(m_vy, m_vx)*3.14 / 180;
	if (ar < 0)
	{
		ar = 360 - abs(ar);
	}

	float br = 3.14 / 180;

	float ix = m_vx;
	float iy = m_vy;

	int p_y = 0;
	int plus = 10;

	for (int i = vy; i < -100; i += plus)
	{
		p_y += 1;
		plus += 100;
	}

	/*if (r < ar)
	{
		ix = ix*cos(-br) - iy*sin(-br);
		iy = iy*cos(-br) + ix*sin(-br);
	}

	else
	{
		ix = ix*cos(br) - iy*sin(br);
		iy = iy*cos(br) + ix*sin(br);
	}
*/
//float a = vx;
//float b = abs(vy);

	float a = m_x - h->GetX();
	float b = abs(m_y - h->GetY());

	if (m_muki == 1)
		Nawa = sqrt((a*a) + (b*b));
	else
		Nawa = sqrt((a*a) + (b*b)) - 32;

	//if (Nawa >m_x - h->GetX() + 64 && Nawa >m_y - h->GetY())
	//{
	//	Nawa = ((b*m_muki));
	//}

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = Nawa;
	src.m_bottom = 64.0f;

	//for (float i = iy; i < 0.0; i+=10)
	//{
	//	r+=1.5;
	//	iy += 0.0f;
	//	ix --;
	//}

	if (iy > 0)
	{
		iy = 0.0f;
	}

	//if (iy < -32.0f)
	//{
	//	//iy = -32.0f;
	//}

	float akasa;
	float kasana;

	kasana = h->GetY();

	if (m_muki == 1)
		//akasa = (iy - (r * p_y)) + h->GetY();
		akasa = (m_y + h->GetY()) / 2;
	else
		akasa = (m_y + h->GetY()) / 2;

	dst.m_top = akasa;
	if (m_muki == 1) {
		dst.m_left = h->GetX() + (m_y - h->GetY()) / 4;
		dst.m_right = (Nawa*m_muki + h->GetX());
	}
	else {
		dst.m_left = h->GetX() + 32 - (m_y - h->GetY()) / 4;
		dst.m_right = (Nawa*m_muki + h->GetX());
	}
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(7, &src, &dst, d, r);

	//鉤部分の描画
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (h->GetMP() == 0)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 31.0f;
		src.m_bottom = 36.0f;
	}
	else
	{
		src.m_top = 0.0f;
		src.m_left = 31.0f;
		src.m_right = 0.0f;
		src.m_bottom = 36.0f;
	}
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	dst.m_top = (-b + h->GetY());
	dst.m_left = (a + h->GetX());
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(20, &src, &dst, c, 0.0f);
}

float CObjNagenawa::Angle()
{
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//vectorの作成
	float vx = (m_x)-h->GetX();
	float vy = (m_y)-h->GetY();

	//角度を求める
	float rr = atan2(-vy, vx);
	rr = rr * 180 / 3.14;

	if (rr < 0)
		rr = 360.0f - abs(rr);

	if (rr > 90)
	{
		rr -= 90;
	}

	rr = rr / 2;

	rr = -(rr*m_muki);

	return rr;
}