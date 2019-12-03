#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjHero :public CObj
{
public:
	CObjHero();
	~CObjHero() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	//���݂̍��W��n��
	float GetX() { return m_x; }
	float GetY() { return m_y; }
	//�����x��n��
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }
	//���X�^�[�g�p�̕ϐ���n��
	float GetWX() { return w_x; }
	float GetWY() { return w_y; }

	//��l���̍��W���O������ύX����
	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }

	//��l���̉����x���O������ύX����
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	//��l���̎藠���̏�������n��
	float GetPS() { return psyuriken; }
	//��l���̎藠���̏��������O������ύX����
	void SetPS(float x) { psyuriken = psyuriken+x; }

	//��l���̃��X�^�[�g�ʒu���O������ύX����
	void SetWX(float x) { w_x = x; }
	void SetWY(float y) { w_y = y; }

	bool GetCF() { return Cflag; }
	//��l���̎c�@����n��
	float GetRE() { return remain; }
	//��l���̎c�@�����O������ύX����
	void SetRE(float x) { remain = remain - x; }
	//��l���̃��[�h��Ԃ�n��
	bool GetChange() { return change; }

	//��l�������g�p��Ԃ��O������ύX����
	void NawaIdo(bool b) { nawa_ido = b; }
	void ReSetN(bool b) { nawa_stop = b; }
	void SetNX(float x) { n_x = x; }
	void SetNY(float y) { n_y = y; }

	//��l���������g�p���Ă����Ԃ�n��
	bool GetNawa() { return nawa_stop; }
	bool GetINawa() { return nawa_ido; }
	void Uflag(bool b) { U_flag = b; }

	//��l���̒��b�ق̃t���O��ݒ�
	void HamuSetUP(bool b) { nezumi = b; }

	//��l���̎��S�t���O���O������ύX����
	void Dflag(bool b) { dead = b; }
	void WDflag(bool b) { Wdead = b; }
	bool GetWDflag() { return Wdead; }

	//��l���̓����蔻��̏�Ԃ��O������ύX����
	void SetUP(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }

	//��l���̓����蔻��̏�Ԃ��O���ɓn��
	bool GetUP() { return m_hit_up; }
	bool GetDown() { return m_hit_down; }
	bool GetLeft() { return m_hit_left; }
	bool GetRight() { return m_hit_right; }

	//�y�ق̏p�m�F
	bool GetDoton() { return doton; }

	//��l���̐퓬�X�^�C�����O���ɓn��
	bool GetMode() { return change; }

	//�E�ɕ���
	void Rightwalk();
	void Leftwalk();

	bool Sworp;//���[�v����p�ϐ�



	//�E�p�t���O
	bool Ninzyutu;

	//�N���A�p�t���O
	bool Cflag;

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
	float remain;//�c�@

	float g_x;//�O���[�o��X�ʒu
	float g_y;//�O���[�o��Y�ʒu

	//���X�^�[�g�p�ʒu
	float w_x;
	float w_y;

	int jamptime;
	float jamppower;

	//�藠���̏�����
	int psyuriken;

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

	//���b�ٗp�ϐ�
	bool nezumi;

	//���S�t���O
	bool dead;
	bool Wdead;

	int d_ani_time;
	int d_ani_frame;

	//�y�ق̏p
	bool doton;

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