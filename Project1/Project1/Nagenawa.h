#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�藠��
class CObjNagenawa :public CObj
{
public:
	CObjNagenawa(int x, int y, int a, float vx, float vy);
	~CObjNagenawa() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	int Pworp;
private:
	float m_x;
	float m_y;

	float m_vx;
	float m_vy;

	//��̌���
	float m_muki;
	//��̏d�͗p�ϐ�
	float grabty;
	//��̒����p�ϐ�
	float Nawa;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�


	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

	//block�Ƃ̏Փˊm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};