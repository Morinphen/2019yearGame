#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjkanban:public CObj
{
public:
	CObjkanban(int x, int y,int t);
	~CObjkanban() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

private:

	int type;//�Ŕ̎�ޔ���
	bool flashing;//�_�ł�����
	float num;//�b�ԃJ�E���g�p

	int m_x;
	int m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

};
