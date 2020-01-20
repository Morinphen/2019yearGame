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
	//�O���I�[�f�B�I�t�@�C���ǂݍ���
	Audio::LoadAudio(0, L"z.wav", SOUND_TYPE::BACK_MUSIC);

	Draw::LoadImage(L"sozai\\gt.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"sozai\\jou.png", 1, TEX_SIZE_1024);
	Draw::LoadImage(L"sozai\\mo.png", 2, TEX_SIZE_1024);
	//Font::SetStrTex(L"�j���J�c");

	//�}�b�v�؂�ւ��I�u�W�F�N�g�쐬
	CObjMapchange* objmc = new CObjMapchange();//�}�b�v�؂�ւ��I�u�W�F�N�g�쐬
	Objs::InsertObj(objmc, OBJ_MAPCHANGE, 10);//�}�b�v�؂�ւ��I�u�W�F�N�g�o�^
}

void CSceneMapchange::Scene()
{

}