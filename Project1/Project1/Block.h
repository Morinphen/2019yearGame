#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjBlock :public CObj
{
public:
	CObjBlock() {};
	~CObjBlock() {};
	void Init();//���ɂ���炢��
	void Action();//���������
	void Draw();//�ǂ�[
private:
	int m_map[10][10];

};