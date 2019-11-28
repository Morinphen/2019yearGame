//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Nezuana.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjNezuana::CObjNezuana(int x, int y, int n)
{
	m_x = x;
	m_y = y;
	Namber = n;
}

//�C�j�V�����C�Y
void CObjNezuana::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	Hits::SetHitBox(this, m_x + 16, m_y + 32, 32, 32, ELEMENT_BLACK, OBJ_NEZUANA, 1);

	testc = 1.0f;
	flag = false;
	Dnamber = false;
	stop = false;
}
//�A�N�V����
void CObjNezuana::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	//�v�f�ԍ������U�ɕύX
	float x = m_x;
	float y = m_y;

	if (flag == true)
	{
		testc = 0.0f;
		Dnamber = true;
		if (stop == false) {
			Hits::DeleteHitBox(this);
			stop = true;
		}
	}

	else {
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + m_scroll + 18, m_y + l_scroll + 32);
	}
}
//�h���[
void CObjNezuana::Draw()
{
	float c[4] = { testc,testc,testc,1.0f };
	RECT_F src;
	RECT_F dst;

	//�u���b�N�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 75.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(29, &src, &dst, c, 0.0f);
}