#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjHero :public CObj
{
public:
	CObjHero(int x,int y);
	~CObjHero() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	float GetGX();
	float GetGY();

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void NawaIdo(bool b) { nawa_ido = b; }
	void ReSetN(bool b) { nawa_stop = b; }
	void SetNX(float x) { n_x = x; }
	void SetNY(float y) { n_y = y; }

	void Uflag(bool b) { U_flag = b; }
	bool GetNawa() { return nawa_stop; }

	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	bool GetUP() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight() { return m_hit_right; }

	bool Sworp;//���[�v����p�ϐ�

	//�E�p�t���O
	bool Ninzyutu;

	//���[�v����ۂ̉摜�؂���ʒu
	float W_cat;
	float W_cat2;

	bool GetBallFlag() { return ball; }
	void SetBallFlag(bool f) { ball = f; }

private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//�p��

	float g_x;//�O���[�o��X�ʒu
	float g_y;//�O���[�o��Y�ʒu

	int jamptime;
	float jamppower;

	//�U�����̐����p�ϐ�
	bool s_atack;
	bool nawa_stop;

	//��ړ��p�ϐ�
	bool nawa_ido;
	float n_x;
	float n_y;
	int idocount;

	//���������t���O
	bool U_flag;
	bool U_scroll;

	//�����p�V�m�r�`�F���W
	bool change;
	bool c_stop;
	float green;

	bool ball;//���ʃt���O
	bool smokeh;//���Ƃ̏Փˊm�F�p
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