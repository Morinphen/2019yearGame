#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�藠��
class CObjSyuriken :public CObj
{
public:
	CObjSyuriken(int x,int y);
	~CObjSyuriken() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[
private:
	float m_x;
	float m_vx;
	float m_y;
	float m_vy;
	float m_posture;//�p��

	CHitBox* hit;

	int jamptime;
	float jamppower;

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

	//�ǂɓ��������Ƃ��A�A�j���[�V������������
	bool Animation;
	float spen;
};