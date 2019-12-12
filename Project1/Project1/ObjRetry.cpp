//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjTitle.h"
#include"main.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

//�Q�[���p�b�h�p
XINPUT_STATE r_state;

//�C�j�V�����C�Y
void CObjRetry::Init()
{
	m_key_flag = false;
	m_posture = true;
}

//�A�N�V����
void CObjRetry::Action()
{
	//�Q�[���p�b�h�p
	DWORD dwResult = XInputGetState(0, &r_state);

	if (Input::GetVKey(VK_UP) == true||r_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_posture = true;
	}
	else if (Input::GetVKey(VK_DOWN) == true||r_state.Gamepad.sThumbLY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
	{
		m_posture = false;
	}
	//�G���^�[�L�[�������ăV�[��:�Q�[���I�[�o�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true||r_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true)
		{
			if (m_posture == true)
			{
				Scene::SetScene(new CSceneGameOver());
			}
			else if (m_posture == false)
			{
				Scene::SetScene(new CSceneMain());
			}
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjRetry::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu



	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 715.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 600.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

	RECT_F srcs; //�`�挳�؂���ʒu
	RECT_F dsts; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	srcs.m_top = 0.0f;
	srcs.m_left = 0.0f;
	srcs.m_right = 512.0f;
	srcs.m_bottom = 512.0f;

	if (m_posture == true)
	{
		//�\���ʒu�̐ݒ�
		dsts.m_top = 160.0f;
		dsts.m_left = 350.0f;
		dsts.m_right =414.0f;
		dsts.m_bottom =224.0f;
	}
	else if (m_posture == false)
	{
		//�\���ʒu�̐ݒ�
		dsts.m_top = 360.0f;
		dsts.m_left = 350.0f;
		dsts.m_right = 414.0f;
		dsts.m_bottom =424.0f;
	}
	//�`��
	Draw::Draw(1, &srcs, &dsts, c, 0.0f);
}