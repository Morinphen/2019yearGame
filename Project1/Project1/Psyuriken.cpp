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
	n_m = -1;
}

//�A�N�V����
void CObjPsyuriken::Action()
{

}

//�h���[
void CObjPsyuriken::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�`��J���[���
	float c2[4] = { 1.0f,1.0f,1.0f,0.8f };

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
	dstf.m_right = 380.0f;
	dstf.m_bottom = 100.0f;
	//�`��
	Draw::Draw(19, &srcf, &dstf, c, 0.0f);
	
	//��l���̏����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	
	RECT_F srcb; //�`�挳�؂���ʒu
	RECT_F dstb; //�`���\���ʒu
	srcb.m_top = 0.0f;
	srcb.m_left = 0.0f;
	srcb.m_right = 512.0f;
	srcb.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dstb.m_top = 0.0f;
	dstb.m_left = 0.0f;
	dstb.m_right = 100.0f;
	dstb.m_bottom = 120.0f;
	//�`��
	Draw::Draw(32, &srcb, &dstb, c, 0.0f);

	RECT_F srcm_u; //�`�挳�؂���ʒu
	RECT_F dstm_u; //�`���\���ʒu
	srcm_u.m_top = 0.0f;
	srcm_u.m_left = 0.0f;
	srcm_u.m_right = 211.0f;
	srcm_u.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dstm_u.m_top = 10.0f;
	dstm_u.m_left = 20.0f;
	dstm_u.m_right = 80.0f;
	dstm_u.m_bottom = 60.0f;
	//�`��
	Draw::Draw(18, &srcm_u, &dstm_u, c, 0.0f);
	mode = hero->GetChange();
	RECT_F srcm; //�`�挳�؂���ʒu
	RECT_F dstm; //�`���\���ʒu

	if (mode == true)
	{
		srcm.m_top = 256.0f;
		srcm.m_left = 0.0f;
		srcm.m_right = 211.0f;
		srcm.m_bottom = 512.0f;
	}
	else
	{
		srcm.m_top = 256.0f;
		srcm.m_left = 211.0f;
		srcm.m_right = 422.0f;
		srcm.m_bottom = 512.0f;
	}

	//�\���ʒu�̐ݒ�
	dstm.m_top = 60.0f;
	dstm.m_left = 20.0f;
	dstm.m_right = 80.0f;
	dstm.m_bottom = 110.0f;
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
	Draw::Draw(21, &srcd, &dstd, c, 0.0f);

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
	Draw::Draw(21, &srcz, &dstz, c, 0.0f);
	RECT_F dstt; //�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dstt.m_top = 0.0f;
	dstt.m_left = 1100.0f;
	dstt.m_right = 1200.0f;
	dstt.m_bottom = 120.0f;
	//�`��
	Draw::Draw(32, &srcb, &dstt, c2, 0.0f);
	if (hero->GetCF() == true)
	{
		RECT_F srcg; //�`�挳�؂���ʒu
		RECT_F dstg; //�`���\���ʒu
		srcg.m_top = 0.0f;
		srcg.m_left = 0.0f;
		srcg.m_right = 512.0f;
		srcg.m_bottom = 512.0f;

		//�\���ʒu�̐ݒ�
		dstg.m_top = 20.0f;
		dstg.m_left = 1110.0f;
		dstg.m_right = 1190.0f;
		dstg.m_bottom = 100.0f;

		//�`��
		Draw::Draw(31, &srcg, &dstg, c, 0.0f);
	}
	RECT_F dstn_b; //�`���\���ʒu

	//�\���ʒu�̐ݒ�
	dstn_b.m_top = 0.0f;
	dstn_b.m_left = 750.0f;
	dstn_b.m_right = 900.0f;
	dstn_b.m_bottom = 120.0f;
	//�`��
	Draw::Draw(32, &srcb, &dstn_b, c2, 0.0f);
	n_m = hero->GetN_M();
	if (n_m>=0)
	{
		RECT_F srcn_m; //�`�挳�؂���ʒu
		RECT_F dstn_m; //�`���\���ʒu
		if (n_m < 4)
		{
			srcn_m.m_top = 0.0f;
			srcn_m.m_left = 0.0f + (184.0f*n_m);;
			srcn_m.m_right =184.0+(184.0f*n_m);
			if (n_m == 1 || n_m == 3)
			{
				srcn_m.m_bottom = 350.0f;
			}
			else
			{
				srcn_m.m_bottom = 512.0f;
			}
		}
		else if (n_m < 8)
		{
			srcn_m.m_top = 512.0f;
			srcn_m.m_left = 0.0f + (184.0f*n_m);;
			srcn_m.m_right = 184.0 + (184.0f*n_m);
			if (n_m == 7)
			{
				srcn_m.m_bottom = 1024.0f;
			}
			else
			{
				srcn_m.m_bottom = 862.0f;
			}
		}
		//�\���ʒu�̐ݒ�
		dstn_m.m_top = 0.0f;
		dstn_m.m_left = 790.0f;
		dstn_m.m_right = 860.0f;
		dstn_m.m_bottom = 120.0f;
		//�`��
		Draw::Draw(33, &srcn_m, &dstn_m, c, 0.0f);
	}
}