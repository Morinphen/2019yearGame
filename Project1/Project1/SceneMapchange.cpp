//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMapchange::CSceneMapchange()
{

}

// �f�X�g���N�^
CSceneMapchange::~CSceneMapchange()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMapchange::InitScene()
{
	Draw::LoadImage(L"change.png", 0, TEX_SIZE_1024);
	//Font::SetStrTex(L"�j���J�c");

	//�}�b�v�؂�ւ��I�u�W�F�N�g�쐬
	CObjMapchange* objmc = new CObjMapchange();//�}�b�v�؂�ւ��I�u�W�F�N�g�쐬
	Objs::InsertObj(objmc, OBJ_MAPCHANGE, 10);//�}�b�v�؂�ւ��I�u�W�F�N�g�o�^
}

void CSceneMapchange::Scene()
{

}