//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Objsetumei.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjsetumei::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjsetumei::Action()
{
	//�G���^�[�L�[�������ăV�[��:�^�C�g���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(0);
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//�h���[
void CObjsetumei::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 00.0f;
	src.m_right = 1024.0f;
	src.m_bottom = 682.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 1200.0f;
	dst.m_bottom = 600.0f;
	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

}