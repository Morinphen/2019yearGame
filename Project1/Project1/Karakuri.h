#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class  CObjKarakuri :public CObj
{
public:
	CObjKarakuri(int x, int y,int n);
	~CObjKarakuri() {};

	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	bool GetON_OFF() { return on_off; }

private:
	int m_x;
	int m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	int num;

	bool on_off;

	//��ʓ��̎��̂݃q�b�g�{�b�N�X������
	bool HitBox_ON;
};
