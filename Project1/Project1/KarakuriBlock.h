#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class  CObjKarakuriblock :public CObj
{
public:
	CObjKarakuriblock(int x, int y, int n);
	~CObjKarakuriblock() {};

	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	void SetDelete(bool b) { Delete = b; }

private:
	int m_x;
	int m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	int num;//���ʔԍ�
	bool Delete;//�폜����
	//��ʓ��̎��̂݃q�b�g�{�b�N�X������
	bool HitBox_ON;
};
