#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�藠��
class CObjNezumi :public CObj
{
public:
	CObjNezumi(int x, int y, int muki);
	~CObjNezumi() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[
private:
	float m_x;
	float m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	float m_posture;//�p��

	bool flag;
	bool Bflag;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������
};