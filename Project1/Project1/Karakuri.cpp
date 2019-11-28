//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\HitBoxManager.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjKarakuri::CObjKarakuri(int x, int y,int n)
{
	m_x = x;
	m_y = y;
	num = n;
}

//�C�j�V�����C�Y
void CObjKarakuri::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	on_off = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK,num, 1);
	HitBox_ON = true;
}

//�A�N�V����
void CObjKarakuri::Action()
{
	//�\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//
		CHitBox* hit = Hits::GetHitBox(this);
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&Input::GetVKey(VK_UP) == true)
		{
			on_off == true;
		}

		//�q�b�g�{�b�N�X����
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, OBJ_MIZUBLOCK, 1);
		}

		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		//���o�[���쓮�����ォ�ǂ���
		if (on_off == false)
		{
			hit->SetPos(m_x + m_scroll, m_y + l_scroll);
		}
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
void CObjKarakuri::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// �\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{

		if (on_off == false)
		{
			//�u���b�N�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;

		}
		else
		{
			//�u���b�N�\��
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 0.0f;
		}

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(16, &src, &dst, c, 0.0f);
	}
}