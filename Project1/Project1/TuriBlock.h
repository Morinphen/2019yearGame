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
	int aaa;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	int m_map[10][100];

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	bool modecheck;//���[�h�`�F���W

	float Dot(float ax, float ay, float bx, float by);//����
	float Cross(float ax, float ay, float bx, float by);//�O��
														/*bool CObjBlock::LineCrossPoint(
														float a1x, float a1y, float a2x, float a2y,
														float b1x, float b1y, float b2x, float b2y,
														float* out_px, float* out_py
														);*/
};