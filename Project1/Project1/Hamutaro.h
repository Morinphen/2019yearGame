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

	//�n�����Y�������邩�ǂ����𔻒�
	bool mapsarch(int x,int y,int muki);
	//�n�����Y�̌��ݒn��Ԃ�
	int mapplace(int x, int y, int muki);
private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;

	//�n�����Y�̂�������
	int Dimax;

	//�n�����Y�̈ʒu�ۑ��p�ϐ�
	int hamnam;

	//�n�����Y�ړ������p�ϐ�
	bool hamstop;

	int map_data[46][100];

	//�������ꂽ�ʒu������ۑ�
	float b_x;
	float b_y;

	//�n�����Y�̃X�s�[�h
	int speed;

	//�����̔��]
	bool m_return;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	float m_posture;//�p��

	bool flag;
	bool Bflag;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};