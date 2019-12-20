#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjTBlock :public CObj
{
public:
	CObjTBlock(int x, int y);
	~CObjTBlock() {};
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
	int m_x;
	int m_y;

	int sm_x;//�����ʒu�ۑ�
	int sm_y;//�����ʒu�ۑ�

	int n;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	int m_map[10][100];

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	int modecheck;//���[�h�`�F���W(1,�~�܂�2,���Ƃ�3,�グ��)

	//��ʓ��̎��̂݃q�b�g�{�b�N�X������
	bool HitBox_ON;

	bool stop;
};