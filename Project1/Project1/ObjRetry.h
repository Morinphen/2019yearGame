#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjRetry :public CObj
{
public:
	CObjRetry(bool map);
	~CObjRetry() {};
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag;//�L�[�t���O
	bool m_posture;//�ォ����
	bool m_type;//�}�b�v�̏�Ԃ��m�F
}; 
