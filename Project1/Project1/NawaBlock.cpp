//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"NawaBlock.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjNBlock::CObjNBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjNBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_NBLOCK, 1);
	HitBox_ON = true;
}
//�A�N�V����
void CObjNBlock::Action()
{
	//�\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�q�b�g�{�b�N�X����
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_NBLOCK, 1);
		}
		//��l���̈ʒu���擾
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		//�v�f�ԍ������U�ɕύX
		float x = m_x;
		float y = m_y;

		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);
	}
	//�\����ʊO�̎�
	else
	{
		//�q�b�g�{�b�N�X�폜
		if (HitBox_ON == true)
		{
			HitBox_ON = false;
			Hits::DeleteHitBox(this);
		}
	}
}
//�h���[
void CObjNBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;
	// �\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�u���b�N�\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;
		Draw::Draw(8, &src, &dst, c, 0.0f);
	}
}