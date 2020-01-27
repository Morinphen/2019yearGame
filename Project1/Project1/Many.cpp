//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Many.h"
#include"GameL\HitBoxManager.h"
#include"main.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Q�[���p�b�h�p
XINPUT_STATE m_state;

//�C�j�V�����C�Y
void CObjMany::Init()
{
	m_key_flag = false;
	open = false;
	H_B = false;
	Giveup = false;
}
//�A�N�V����
void CObjMany::Action()
{
	//�Q�[���p�b�h�p
	DWORD dwResult = XInputGetState(0, &m_state);

	if (open == true) {
		if (Input::GetVKey(VK_UP) == true || m_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			H_B = false;
		}
		else if (Input::GetVKey(VK_DOWN) == true || m_state.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
		{
			H_B = true;
		}
	}

	//�G���^�[�L�[�������ăV�[��:�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true || m_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true && open == false)
		{
			open = true;
		}

		else
		{
			if (H_B == false && Giveup == false || H_B == true && Giveup == true) {
				if (m_key_flag == true) {
					open = false;
					H_B = false;
					Giveup = false;
				}
			}

			else {
				Giveup = true;
				if (m_key_flag == true && H_B == false)
				{
					Scene::SetScene(new CSceneTitle());
				}
			}
		}
		m_key_flag = false;
	}

	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjMany::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;


	if (open == true) {
		
		//�w�i�\��
		//�Ŕ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 512.0f;
		src.m_bottom = 512.0f;
		dst.m_top = 100.0f;
		dst.m_left = 250.0f;
		dst.m_right = 950.0f;
		dst.m_bottom = 720.0f;
		Draw::Draw(69, &src, &dst, c, 0.0f);

		//�߂ɂ�[or�{����
		if (Giveup == false) {
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 64.0f;
			dst.m_top = 170.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 234.0f;
		}
		else
		{
			src.m_top = 192.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 256.0f;
			dst.m_top = 170.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 234.0f;
		}
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//�����[�ƂŌ���
		src.m_top = 384.0f;
		src.m_left = 0.0f;
		src.m_right = 192.0f;
		src.m_bottom = 468.0f;
		dst.m_top = 220.0f;
		dst.m_left = 420.0f;
		dst.m_right = 792.0f;
		dst.m_bottom = 300.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//�C�����sor�͂�
		if (Giveup == false) {
			src.m_top = 128.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 192.0f;
			dst.m_top = 300.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 364.0f;
		}
		else {
			src.m_top = 256.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 320.0f;
			dst.m_top = 270.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 394.0f;
		}
		if (H_B == true)
			c[3] = 0.5f;
		else
			c[3] = 1.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//�����Ƃ��or������
		if (Giveup == false) {
			src.m_top = 64.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 128.0f;
			dst.m_top = 400.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 464.0f;
		}
		else {
			src.m_top = 320.0f;
			src.m_left = 0.0f;
			src.m_right = 192.0f;
			src.m_bottom = 384.0f;
			dst.m_top = 370.0f;
			dst.m_left = 420.0f;
			dst.m_right = 792.0f;
			dst.m_bottom = 494.0f;
		}
		if (H_B == false)
			c[3] = 0.5f;
		else
			c[3] = 1.0f;
		Draw::Draw(14, &src, &dst, c, 0.0f);

		//�J�[�\���o��
		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 32.0f;
		src.m_bottom = 32.0f;

		if (H_B == false)
		{
			//�\���ʒu�̐ݒ�
			dst.m_top = 300.0f;
			dst.m_left = 350.0f;
			dst.m_right = 414.0f;
			dst.m_bottom = 364.0f;
		}
		else if (H_B == true)
		{
			//�\���ʒu�̐ݒ�
			dst.m_top = 400.0f;
			dst.m_left = 350.0f;
			dst.m_right = 414.0f;
			dst.m_bottom = 464.0f;
		}

		c[3] = 1.0f;
		Draw::Draw(3, &src, &dst, c, 0.0f);

	}
}