#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjNezuana :public CObj
{
public:
	CObjNezuana(int x, int y,int n);
	~CObjNezuana() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	bool GetDnamber() { return Dnamber; }

	void SetFlag(float s) { flag = s; }

private:
	int m_x;
	int m_y;

	bool flag;
	float testc;

	//���g�̔ԍ���ۑ�����ϐ�
	int Namber;
	bool Dnamber;

	bool stop;

	int m_map[10][100];

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�
};