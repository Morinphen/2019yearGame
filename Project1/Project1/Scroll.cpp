//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Scroll.h"
#include"GameL\HitBoxManager.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjScroll::CObjScroll(int map[46][100])
{
	memcpy(m_map, map, sizeof(int)*(46 * 100));
}

//�C�j�V�����C�Y
void CObjScroll::Init()
{
	m_scroll = 64.0f*-0.0f;
	l_scroll = 64.0f*-36.0f;
}
//�A�N�V����
void CObjScroll::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx > 500 && hx < 600)
	{
		mn_scroll = 500 - hx;
	}
	if (hy > 80 && hy < 500)
	{
		mn_scroll = 500 - hx;
	}

	//����X�N���[�����C��
	if (hx < 500)
	{
		hero->SetX(500);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	//�O���X�N���[�����C��
	if (hx > 600)
	{
		hero->SetX(600);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	if (hy < 0)
	{
		hero->SetY(500);//��l���̓��C���𒴂��Ȃ��悤��
		l_scroll += 64 * 9;//��l�����{������������������
	}

	////�����X�N���[�����C��
	if (hy > 600 && l_scroll>-64*46)
	{
	    hero->SetY(0);//��l���̓��C���𒴂��Ȃ��悤��
		l_scroll -= 64 * 9;//��l�����{������������������
	}

}
//�h���[
void CObjScroll::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�w�i�\��
	src.m_top = 300.0f - (l_scroll / 4);
	src.m_left = 100.0f - (m_scroll / 4);
	src.m_right = 700.0f - (m_scroll / 4);
	src.m_bottom = 1000.0f - (l_scroll / 4);
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 620.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);
}

//�\����ʂ̒��ɂ��邩���ׂ�
bool CObjScroll::Inscrooll_check(int x, int y)
{
	if (x+64 >= -m_scroll&&
		x    <= WINDOW_SIZE_W-m_scroll&&
		y+64 >= -l_scroll&&
		y    <= 600-l_scroll)
		return true;
	else
		false;
}

void CObjScroll::Resporn_check(int x, int y)
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	if (hx > 500 && hx < 600)
	{
		mn_scroll = 500 - hx;
	}
	if (hy > 80 && hy < 500)
	{
		mn_scroll = 500 - hx;
	}

	//����X�N���[�����C��
	if (hx < 500)
	{
		hero->SetX(500);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	//�O���X�N���[�����C��
	if (hx > 600)
	{
		hero->SetX(600);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	if (hy < 0)
	{
		hero->SetY(0);//��l���̓��C���𒴂��Ȃ��悤��
		l_scroll -= hero->GetVY();//��l�����{������������������
	}

	////�����X�N���[�����C��
	if (hy > 500)
	{
		hero->SetY(400);//��l���̓��C���𒴂��Ȃ��悤��
		//l_scroll -= hero->GetVY();//��l�����{������������������
	}
}

void CObjScroll::Donden_check(int x, int y)
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	int yy = y;

	int Yz = 0;

	for (; yy > 64 * 9;)
	{
		yy -= 64.0 * 9;
		Yz++;
	}

	hero->SetY(yy);

	l_scroll = -(64*9)*Yz;
}