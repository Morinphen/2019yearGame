#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjScroll :public CObj
{
public:
	CObjScroll(int map[46][100]);
	~CObjScroll() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	float GetMNScroll() { return mn_scroll; }
	float GetLNScroll() { return ln_scroll; }
	bool Inscrooll_check(int x, int y);

	int m_map[46][100];
private:
	int m_x;
	int m_y;


	float mn_scroll;//�~�j�}�b�v�p�X�N���[���ϐ�
	float ln_scroll;//�~�j�}�b�v�p�X�N���[���ϐ�
	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	float w_m_scroll;//���[�v��ۑ����E�X�N���[���p�ϐ�
	float w_l_scroll;//���[�v��ۑ��㉺�X�N���[���p�ϐ�

};