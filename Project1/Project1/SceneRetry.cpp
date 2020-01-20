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
CSceneRetry::CSceneRetry(bool map)
{
	m_type = map;
}

// �f�X�g���N�^
CSceneRetry::~CSceneRetry()
{

}

//�Q�[�����C�����������\�b�h
void CSceneRetry::InitScene()
{
	Draw::LoadImage(L"retry.png", 0, TEX_SIZE_1024);
	Draw::LoadImage(L"ka.png", 1, TEX_SIZE_512);
	Font::SetStrTex(L"�j���J�c");
	//�O���I�[�f�B�I�t�@�C���ǂݍ���
	Audio::LoadAudio(0, L"gameover.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(-0.3);
	v = Audio::VolumeMaster((1.0-v));
	v = Audio::VolumeMaster(-0.3);
	Audio::Start(0);

	//���g���C�I�u�W�F�N�g�쐬
	CObjRetry* obj = new CObjRetry(m_type);//���g���C�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_RETRY, 10);//���g���C�I�u�W�F�N�g�o�^
}

void CSceneRetry::Scene()
{

}