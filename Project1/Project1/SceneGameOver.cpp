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
CSceneGameOver::CSceneGameOver()
{

}

// �f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C�����������\�b�h
void CSceneGameOver::InitScene()
{
	Draw::LoadImage(L"sozai\\GameOver.png", 0, TEX_SIZE_1024);
	Font::SetStrTex(L"�j���J�c");
	//�O���I�[�f�B�I�t�@�C���ǂݍ���
	Audio::LoadAudio(0, L"gameover2.wav", SOUND_TYPE::BACK_MUSIC);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float v = Audio::VolumeMaster(-0.5);
	v=Audio::VolumeMaster((1.0-v));
	v = Audio::VolumeMaster(-0.5);
	Audio::Start(0);

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_GAMEOVER, 10);//�Q�[���I�[�o�[�I�u�W�F�N�g�o�^
}

void CSceneGameOver::Scene()
{

}