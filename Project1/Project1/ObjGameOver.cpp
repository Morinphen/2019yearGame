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
XINPUT_STATE g_state;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjGameOver::Action()
{
	//�Q�[���p�b�h�p
	DWORD dwResult = XInputGetState(0, &g_state);

	//�G���^�[�L�[�������ăV�[��:�^�C�g���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true ||g_state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjGameOver::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	

	 //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 00.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 988.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left =0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 900.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}