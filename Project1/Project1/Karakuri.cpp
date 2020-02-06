//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Q�[���p�b�h�p
XINPUT_STATE k_state;

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

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK,OBJ_KARAKURI, 1);
	HitBox_ON = true;
}

//�A�N�V����
void CObjKarakuri::Action()
{
	//�Q�[���p�b�h�p
	DWORD dwResult = XInputGetState(0, &k_state);

	//���j���[�p�̏��擾
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		////�\����ʓ��̎�
		CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
		if (scroll->Inscrooll_check(m_x, m_y) == true)
		{
			//�q�b�g�{�b�N�X����
			if (HitBox_ON == false)
			{
				HitBox_ON = true;
				Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, OBJ_KARAKURI, 1);
			}

			//���o�[�쓮
			CHitBox* hit = Hits::GetHitBox(this);
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&Input::GetVKey(VK_UP) == true && on_off == false ||
				hit->CheckObjNameHit(OBJ_HERO) != nullptr&&k_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE&&on_off == false)
			{
				Audio::Start(6);
				on_off = true;
			}

			m_scroll = scroll->GetScroll();
			l_scroll = scroll->GetYScroll();

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
		//���o�[�̌��������߂�
		if (num == 61||num==62)
		{
			if (on_off == false)
			{
				//�u���b�N�\��
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 63.0f;
				src.m_bottom = 64.0f;

			}
			else
			{
				//�u���b�N�\��
				src.m_top = 64.0f;
				src.m_left = 0.0f;
				src.m_right = 63.0f;
				src.m_bottom = 0.0f;
			}
		}
		else
		{
			if (on_off == false)
			{
				//�u���b�N�\��
				src.m_top = 0.0f;
				src.m_left = 64.0f;
				src.m_right = -1.0f;
				src.m_bottom = 64.0f;

			}
			else
			{
				//�u���b�N�\��
				src.m_top = 64.0f;
				src.m_left = 64.0f;
				src.m_right = -1.0f;
				src.m_bottom = 0.0f;
			}
		}

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(16, &src, &dst, c, 0.0f);
	}
}