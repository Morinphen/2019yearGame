#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�藠��
class CObjDonden :public CObj
{
public:
	CObjDonden(int x, int y, int namber, bool b);
	~CObjDonden() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	int Pworp;
private:

	int Worp(int a);
	int TagWorp(int a);

	int Wnamber;//���[�v��̔ԍ���ۑ�����

	float m_x;
	float m_y;

	float m_scroll;//���E�X�N���[���p�ϐ�
	float l_scroll;//�㉺�X�N���[���p�ϐ�

	float red;
	//���[�v����ۂɃA�j���[�V������������
	bool Wanimation;
	bool Wanimation2;

	//���ړ�����p�ϐ�
	bool N_stop;

	//�y�ٗp
	bool doton_flag;

	//��l���̈ʒu�̊m�F
	bool s_down;

	//�ǂ�ł�Ԃ��ŉB��
	bool hide;

	int D_tag[50][3];//�y�A�̂ǂ�ł�Ԃ���T��

	int m_ani_time;//�A�j���[�V�����t���[��
	int m_ani_frame;//�`��t���[��

	float m_speed_power;//�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V��������

	//��ʓ��̎��̂݃q�b�g�{�b�N�X������
	bool HitBox_ON;
};