#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjSmokeball : public CObj
{
public:
	CObjSmokeball(int x, int y, int m);
	~CObjSmokeball() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	void SetDelete(bool d) { smokeball_delete = d; }
	void Setmodecheck(bool c) { modecheck = c; }

private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//�p��

	float g_x;
	float g_y;

	CHitBox* hit;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��
	int m_muki;//���ʂ̓��������

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

	int smoke_time;//�����o���Ă��鎞��
	bool smokeball_delete;//�{�[���̍폜

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	bool modecheck;//���[�h�`�F���W

	//block�Ƃ̏Փˊm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};