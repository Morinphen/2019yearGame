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
CScenesetumei::CScenesetumei()
{

}

// �f�X�g���N�^
CScenesetumei::~CScenesetumei()
{

}

//�Q�[�����C�����������\�b�h
void CScenesetumei::InitScene()
{
	Draw::LoadImage(L"sozai\\setumei.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"�j���J�c");
	//�O���I�[�f�B�I�t�@�C���ǂݍ���

	Audio::LoadAudio(0, L"music\\setumei.wav", SOUND_TYPE::BACK_MUSIC);

	float v = Audio::VolumeMaster(-0.5);
	v = Audio::VolumeMaster((1.0 - v));
	v = Audio::VolumeMaster(-0.5);
	Audio::Start(0);

	CObjsetumei* obj = new CObjsetumei();//�����I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_SETUMEI, 10);//�����I�u�W�F�N�g�o�^
}

void CScenesetumei::Scene()
{

}