#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G
class CObjMuscleEnemy :public CObj
{
public:
	CObjMuscleEnemy(int x, int y);
	~CObjMuscleEnemy() {};
	void Init(); //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw(); //�h���[

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVX() { return m_vx; }
	float GetVY() { return m_vy; }
	float GetMV() { return m_move; }

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVX(float vx) { m_vx = vx; }
	void SetVY(float vy) { m_vy = vy; }
	void SetM_P(float x) { m_posture = x; }
	void Set_MOVE(bool a) { m_move = a; }

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
	void SetF(bool b) { find = b; }
	void SetD(bool b) { de = b; }
private:
	float m_px; //�ʒu
	float m_py;
	float m_vx; //�ړ��x�N�g��
	float m_vy;
	float m_posture; //�p��

	bool find;
	bool m_move;
	bool de;
	bool hit_hm;
	bool hit_HA;
	bool hatena;

	int m_ani_time; //�A�j���[�V����
	int m_ani_frame;//�`��t���[��
	int m_posture_time;//�p���ς���܂ł̎���
	int sm_x;//�藠����x���W
	bool p;//�藠���̌���

	bool crhitbox;
	float m_speed_power; //�X�s�[�h�p���[
	float m_ani_max_time; //�A�j���[�V��������Ԋu�ő�l

						  //block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool HitBox_ON;
};
