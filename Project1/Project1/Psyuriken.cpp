//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawFont.h"
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Psyuriken.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPsyuriken::Init()
{
	ps = 0;
	re = 0;
}

//�A�N�V����
void CObjPsyuriken::Action()
{

}

//�h���[
void CObjPsyuriken::Draw()
{
	//
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F srcf; //�`�挳�؂���ʒu
	RECT_F dstf; //�`���\���ʒu

				 //�؂���ʒu�̐ݒ�
	srcf.m_top = 0.0f;
	srcf.m_left = 0.0f;
	srcf.m_right = 512.0f;
	srcf.m_bottom = 150.0f;

	//�\���ʒu�̐ݒ�
	dstf.m_top = 0.0f;
	dstf.m_left = 100.0f;
	dstf.m_right = 580.0f;
	dstf.m_bottom = 100.0f;
	//�`��
	Draw::Draw(19, &srcf, &dstf, c, 0.0f);

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 20.0f;
	dst.m_left = 350.0f;
	dst.m_right = 478.0f;
	dst.m_bottom = 84.0f;
	//�`��
	Draw::Draw(17, &src, &dst, c, 0.0f);
	//��l���̏����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	RECT_F srcs; //�`�挳�؂���ʒu
	RECT_F dsts; //�`���\���ʒu
	ps=hero->GetPS();
	//�؂���ʒu�̐ݒ�
	if (ps > 3)
	{
		srcs.m_top = 2.0f;
		srcs.m_left = 130.0f + 64*(5-ps);
		srcs.m_right = 191.0f + 64 * (5-ps);
		srcs.m_bottom = 64.0f;
	}
	else
	{
		srcs.m_top = 2.0f;
		srcs.m_left = 130.0f + 64 * (5-ps);
		srcs.m_right = 184.0f + 64 * (5-ps);
		srcs.m_bottom = 64.0f;
	}
	//�\���ʒu�̐ݒ�
	dsts.m_top = 20.0f;
	dsts.m_left = 478.0f;
	dsts.m_right = 542.0f;
	dsts.m_bottom = 84.0f;
	//�`��
	Draw::Draw(17, &srcs, &dsts, c, 0.0f);

	RECT_F srcm; //�`�挳�؂���ʒu
	RECT_F dstm; //�`���\���ʒu
	mode = hero->GetMode();
	if (mode == false)
	{
		srcm.m_top = 0.0f;
		srcm.m_left = 0.0f;
		srcm.m_right = 256.0f;
		srcm.m_bottom = 256.0f;
	}
	else
	{
		srcm.m_top = 0.0f;
		srcm.m_left = 256.0f;
		srcm.m_right = 512.0f;
		srcm.m_bottom = 256.0f;
	}

	//�\���ʒu�̐ݒ�
	dstm.m_top = 0.0f;
	dstm.m_left = 0.0f;
	dstm.m_right = 100.0f;
	dstm.m_bottom = 120.0f;
	//�`��
	Draw::Draw(18, &srcm, &dstm, c, 0.0f);

	RECT_F srcd; //�`�挳�؂���ʒu
	RECT_F dstd; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	srcd.m_top = 0.0f;
	srcd.m_left = 0.0f;
	srcd.m_right = 128.0f;
	srcd.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dstd.m_top = 20.0f;
	dstd.m_left = 150.0f;
	dstd.m_right = 278.0f;
	dstd.m_bottom = 84.0f;
	//�`��
	Draw::Draw(25, &srcd, &dstd, c, 0.0f);

	RECT_F srcz; //�`�挳�؂���ʒu
	RECT_F dstz; //�`���\���ʒu
	re = hero->GetRE();
	//�؂���ʒu�̐ݒ�
	if (re > 3)
	{
		srcz.m_top = 2.0f;
		srcz.m_left = 130.0f + 64 * (5 - re);
		srcz.m_right = 191.0f + 64 * (5 - re);
		srcz.m_bottom = 64.0f;
	}
	else
	{
		srcz.m_top = 2.0f;
		srcz.m_left = 130.0f + 64 * (5 - re);
		srcz.m_right = 184.0f + 64 * (5 - re);
		srcz.m_bottom = 64.0f;
	}
	//�\���ʒu�̐ݒ�
	dstz.m_top = 20.0f;
	dstz.m_left = 278.0f;
	dstz.m_right = 342.0f;
	dstz.m_bottom = 84.0f;
	//�`��
	Draw::Draw(25, &srcz, &dstz, c, 0.0f);
}