//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Nagenawa.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjNagenawa::CObjNagenawa(int x, int y, int a, float vx, float vy)
{
	m_x = x;
	m_y = y - 10;

	m_vx = vx / 50;

	m_vy = vy / 40;

	m_muki = a;
}

//�C�j�V�����C�Y
void CObjNagenawa::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[��������

	m_vy = -m_vy * 2;
	grabty = m_vy;

	Nawa = 0;

	//m_vy = -15;

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�������o��

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_NAGENAWA, 1);
}
//�A�N�V����
void CObjNagenawa::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	if (hit->CheckObjNameHit(OBJ_BLOCK) != nullptr)
	{
		CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
		h->ReSetN(false);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	else if (hit->CheckObjNameHit(OBJ_NBLOCK) != nullptr)
	{
		CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float a = abs(m_y - h->GetY());
		h->ReSetN(false);
		h->NawaIdo(true);
		h->SetNX(m_x - h->GetX());
		h->SetNY(a-20);
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	m_x += m_vx*m_muki;

	//�d��
	m_vy += (-grabty / 3) / 16.0f;
	m_y += m_vy;

	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	hit->SetPos(m_x, m_y);
}
//�h���[
void CObjNagenawa::Draw()
{
	float c[4] = { 0.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	float d[4] = { 0.0f,0.0f,0.0f,1.0f };

	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//vector�̍쐬
	float vx = (m_x + (-m_scroll)) - h->GetX();
	float vy = (m_y + (-l_scroll)) - h->GetY();

	//�p�x�����߂�
	float r = atan2(vy, vx);
	r = r * 180 / 3.14;

	r = 360.0f - abs(r);

	float a = abs(m_vy);
	float b = abs(m_vx);

	Nawa += (a + b);

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = Nawa;
	src.m_bottom = 64.0f;

	dst.m_top = 0.0f + h->GetY() - (Nawa - b) / 7;
	dst.m_left = 0.0f + h->GetX();
	dst.m_right = Nawa + h->GetX();
	dst.m_bottom = 64.0f + h->GetY() - (Nawa - b) /7;

	Draw::Draw(7, &src, &dst, d, -r);
}