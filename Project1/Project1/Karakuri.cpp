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

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KARAKURI, 1);
}

//�A�N�V����
void CObjKarakuri::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	CHitBox* hit = Hits::GetHitBox(this);

	if (on_off == false)
	{
		if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&Input::GetVKey(VK_UP))
		{
			Hits::DeleteHitBox(this);

			if (num == 1)
			{
				//���������Ƀ}�b�v�ɕύX����
				on_off = true;
			}
			else if (num == 2)
			{
				//���������Ƀ}�b�v�ɕύX����
				on_off = true;
			}
			else if (num == 3)
			{
				//���������Ƀ}�b�v�ɕύX����
				on_off = true;
			}
		}
		hit->SetPos(m_x + m_scroll, m_y + l_scroll);
	}

	
}

//�h���[
void CObjKarakuri::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

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