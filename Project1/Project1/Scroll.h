#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjScroll :public CObj
{
public:
	CObjScroll() {};
	~CObjScroll() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }
private:
	int m_x;
	int m_y;

	int m_map[10][100];

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

};