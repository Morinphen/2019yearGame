#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class  CObjKarakuriblock :public CObj
{
public:
	CObjKarakuriblock(int x, int y, int n);
	~CObjKarakuriblock() {};

	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

private:
	int m_x;
	int m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	int num;//���ʔԍ�
};
