#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjMany :public CObj
{
public:
	CObjMany() {};
	~CObjMany() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[

	bool GetOpen() { return open; }
private:
	bool m_key_flag;//�L�[�t���O
	bool open;//���j���[��ʂ��o��������
	bool H_B;
	bool Giveup;
};