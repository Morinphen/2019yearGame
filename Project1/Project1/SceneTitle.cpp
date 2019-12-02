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
CSceneTitle::CSceneTitle()
{

}

// �f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C�����������\�b�h
void CSceneTitle::InitScene()
{
	Draw::LoadImage(L"title.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"�j���J�c");
	//�O���I�[�f�B�I�t�@�C���ǂݍ���
	Audio::LoadAudio(0, L"title.wav", SOUND_TYPE::BACK_MUSIC);

	Audio::LoadAudio(1, L"titleselect.wav", SOUND_TYPE::EFFECT);
	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(-0.4);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.4);
	Audio::Start(0);

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();//�^�C�g���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g�o�^
}

void CSceneTitle::Scene()
{

}