#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjPsyuriken :public CObj
{
public:
	CObjPsyuriken() {};
	~CObjPsyuriken() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
	void SetChange(bool b) { change = b; }
private:
	int ys;
	int fs;
	int ps;
	int re;
	bool mode;
	bool change;
	float n_m;
};