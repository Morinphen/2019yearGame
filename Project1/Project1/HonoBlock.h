#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjHonoBlock :public CObj
{
public:
	CObjHonoBlock(int x, int y);
	~CObjHonoBlock() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	void SetScrooll(float s) { m_scroll = s; }
	float GetScroll() { return m_scroll; }

	void SetYScrooll(float s) { l_scroll = s; }
	float GetYScroll() { return l_scroll; }

	////��l���ƕǂ̌�������
	//bool HeroBlockCrossPoint(
	//	float x, float y, float vx, float vy,
	//	float *out_px, float *out_py, float* out_len
	//);

private:
	

	float m_x;
	float m_y;

	//���X�����ꏊ��ۑ�����
	float b_x;
	float b_y;

	float m_vx;
	float m_vy;

	int m_map[10][100];

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	bool enzyou;

	//��ʓ��̎��̂݃q�b�g�{�b�N�X������
	bool HitBox_ON;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};