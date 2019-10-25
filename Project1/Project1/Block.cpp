//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Block.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjBlock::CObjBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_BLOCK, 1);
}
//�A�N�V����
void CObjBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//�G�̈ʒu���擾
	CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
	float ex = enemy->GetX();
	float ey = enemy->GetY();

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	//�v�f�ԍ������U�ɕύX
	float x = m_x;
	float y = m_y;

	//��l���ƃu���b�N�̓����蔻��
	if ((hx + (-m_scroll) + 64.0f > x) && (hx + (-m_scroll) < x + 64.0f) && (hy + (-l_scroll) + 64.0f > y) && (hy + (-l_scroll) < y + 64.0f))
	{
		//�㉺���E����

		//vector�̍쐬
		float vx = (hx + (-m_scroll)) - x;
		float vy = (hy + (-l_scroll)) - y;
		//���������߂�
		float len = sqrt(vx*vx + vy*vy);

		//�p�x�����߂�
		float r = atan2(vy, vx);
		r = r * 180 / 3.14;
		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//len��������̒����̂��Z���ꍇ����ɓ���
		if (len < 88.0f) {
			//�p�x�ŏ㉺���E�𔻒�
			if ((r < 45 && r>=0) || r > 315)
			{
				//�E
				hero->SetRight(true);//��l���̍��̕������Փ˂��Ă���
				hero->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
				hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
			}
			else if (r > 45 && r < 135)
			{
				//��
				hero->SetDown(true);//��l�����猩�ĉ��̕������Փ˂��Ă���
				hero->SetY(y - 64.0f + (l_scroll));//�u���b�N�̈ʒu-��l���̕�
				hero->SetVY(0.0f);
			}
			else if (r > 135 && r < 225)
			{
				//��
				hero->SetLeft(true);//��l���̉E�̕������Փ˂��Ă���
				hero->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
				hero->SetVX(-hero->GetVX()*0.1f);//-VX*�����W��
			}
			else if (r > 225 && r < 315)
			{
				//��
				hero->SetUP(true);//��l�����猩�ď�̕������������Ă���
				hero->SetY(y + 64.0f + (l_scroll));//�u���b�N�̈ʒu+��l���̕�
				if (hero->GetVY() < 0)
				{
					hero->SetVY(0.0f);
				}
			}
		}
	}

	//��l���ƃu���b�N�̓����蔻��
	if ((ex + (-m_scroll) + 64.0f > x) && (ex + (-m_scroll) < x + 64.0f) && (ey + (-l_scroll) + 64.0f > y) && (ey + (-l_scroll) < y + 64.0f))
	{
		//�㉺���E����

		//vector�̍쐬
		float evx = (ex + (-m_scroll)) - x;
		float evy = (ey + (-l_scroll)) - y;
		//���������߂�
		float elen = sqrt(evx*evx + evy*evy);

		//�p�x�����߂�
		float er = atan2(evy, evx);
		er = er * 180 / 3.14;
		if (er <= 0.0f)
			er = abs(er);
		else
			er = 360.0f - abs(er);

		//len��������̒����̂��Z���ꍇ����ɓ���
		if (elen < 88.0f) {
			//�p�x�ŏ㉺���E�𔻒�
			if ((er < 45 && er >= 0) || er > 315)
			{
				//�E
			    enemy->SetRight(true);//�G�̍��̕������Փ˂��Ă���
				enemy->SetX(x + 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
				enemy->SetVX(-enemy->GetVX()*0.1f);//-VX*�����W��
			}
			else if (er > 45 && er < 135)
			{
				//��
				enemy->SetDown(true);//�G���猩�ĉ��̕������Փ˂��Ă���
				enemy->SetY(y - 64.0f + (l_scroll));//�u���b�N�̈ʒu-��l���̕�
				enemy->SetVY(0.0f);
			}
			else if (er > 135 && er < 225)
			{
				//��
				enemy->SetLeft(true);//�G�̉E�̕������Փ˂��Ă���
			    enemy->SetX(x - 64.0f + (m_scroll));//�u���b�N�̈ʒu+��l���̕�
				enemy->SetVX(-enemy->GetVX()*0.1f);//-VX*�����W��
			}
			else if (er > 225 && er < 315)
			{
				//��
				enemy->SetUP(true);//�G���猩�ď�̕������������Ă���
				enemy->SetY(y + 64.0f + (l_scroll));//�u���b�N�̈ʒu+��l���̕�
				if (enemy->GetVY() < 0)
				{
					enemy->SetVY(0.0f);
				}
			}
		}
	}

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//�h���[
void CObjBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�u���b�N�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
}

////���ϊ֐�
////����1,2float ax,ay:A�x�N�g��
////����3,4float bx,by:B�x�N�g��
////�߂�l�@float :�ˉe
////���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
//float CObjBlock::Dot(float ax, float ay, float bx, float by)
//{
//	float t = 0.0f;
//	t = ax*bx + ay*by;
//	return t;
//}
//
////�O�ϊ֐�
////����1,2float ax,ay:A�x�N�g��
////����3,4float bx,by:B�x�N�g��
////�߂�l�@float :�ˉe
////���e�@A�x�N�g����B�x�N�g���ŊO�ς��s���ˉe�����߂�
//float CObjBlock::Cross(float ax, float ay, float bx, float by)
//{
//	float t = 0.0f;
//	t = ax*by + ay*bx;
//	return t;
//}
////���������߂�}�N��
//#define SGN(x)1-(x<=0)-(x<0)
//
////���Ɛ��ƌ�������
////���� float 1,2 a1x,a1y:���x�N�g��A�̎n�_
////���� float 3,4 a2x,a2y:���x�N�g��A�̏I�_
////���� float 5,6 b1x,b1y:�x�N�g��B�̎n�_
////���� float 7,8 b2x,b2y:�x�N�g��B�̏I�_
////���� float 9,10 out_px,out_py :��������x�N�g���̌�_�ʒu
////�߂�l bool :true=��_���� false=�Ȃ�
////���e:��������A�EB�x�N�g���̌�_�������Aout_px��out_py�ɕԂ�
//bool CObjBlock::LineCrossPoint(
//	float a1x, float a1y, float a2x, float a2y,
//	float b1x, float b1y, float b2x, float b2y,
//	float* out_px, float* out_py
//)
//{
//	//�G���[�R�[�h
//	*out_px - 9999.0f; *out_py = -9999.0f;
//
//	//A�x�N�g���쐬(a2��a1)
//	float ax = a2x - a1x; float ay = a2y - a1y;
//
//	//B�x�N�g���쐬(b2��b1)
//	float bx = b2x - b1x; float by = b2y - b1y;
//
//	//C�x�N�g���쐬(b1��a1)
//	float cx = b1x - a1x; float cy = b1y - a1y;
//
//	//D�x�N�g���쐬(b2��a1)
//	float dx = b2x - a1x; float dy = b2y - a1y;
//
//	//A*C�̎ˉe��A*B�̎ˉe�����߂�
//	float t1 = Cross(ax, ay, cx, cy);
//	float t2 = Cross(ax, ay, dx, dy);
//
//	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
//	if (SGN(t1) == SGN(t2))
//		return false;
//
//	//�ˉe���Βl��
//	t1 = abs(t1); t2 = abs(t2);
//
//	//��_�����߂�
//	float px = bx*(t1 / (t1 + t2)) + b1x;
//	float py = by*(t1 / (t1 + t2)) + b1y;
//
//	//AP�x�N�g��(p��a1)
//	float apx = px - a1x; float apy = py - a1y;
//
//	//BP�x�N�g��(p��a2)
//	float bpx = px - a2x; float bpy = py - a2y;
//
//	//A�EAP�̎ˉe��A�EB�̎ˉe�����߂�
//	float w1 = Dot(ax, ay, apx, apy);
//	float w2 = Dot(ax, ay, bpx, bpy);
//
//	//�����`�F�b�N
//	if (SGN(w1) == SGN(w2))
//		return false;//��_���O
//
//	//��_��Ԃ�
//	*out_px = px; *out_py = py;
//	return true;
//}
//
////��l���ƕǂ̌�������֐�
////����1,2 float x,y:��l���̈ʒu
////����3,4 float vx,vy:��l���̈ړ��x�N�g��
////����5,6 float* out_x,out_y:Block�Ƃ̌�_
////����7 float* out:�ʒu�����_�܂ł̋���
////��l���̈ʒu+�ړ��x�N�g���Ɗe�u���b�N�̕ӂŌ�_������s��
////�ł��߂���_�̈ʒu�Ƌ�����Ԃ�
//bool CObjBlock::HeroBlockCrossPoint(
//	float x, float y, float vx, float vy,
//	float *out_px, float *out_py, float* out_len
//)
//{
//	bool pb = false;//��_�m�F�p
//	float len = 89999.0f;
//	//�u���b�N�̕Ӄx�N�g��
//	float edge[4][4] =
//	{
//		{ 0,0,64, 0 },//���
//		{ 64,0,64,64 },//�E��
//		{ 64,64,0,64 },//����
//		{ 0,64,0,0 },//����
//	};
//
//	for (int k = 0; k < 4; k++)
//	{
//		//��_��T��
//		float px, py;
//		bool b;
//		float l = 0.0f;
//		b = LineCrossPoint(x, y, x + vx, y + vy,
//			64 + edge[k][0], 64 + edge[k][1], 64 + edge[k][2], 64 + edge[k][3],
//			&px, &py);
//		//��_�`�F�b�N
//		if (b == true)
//		{
//			//��_�Ƃ̋��������߂�
//			l = sqrt((px - x)*(px - x) + (py - y)*(py - y));
//
//			//��������_�̒��ōł��������Z�����̂�T��
//			if (len > l)
//			{
//				len = l;
//				*out_px = px;
//				*out_py = py;
//				pb = true;
//			}
//		}
//	}
//
//	*out_len = len;
//	return pb;
//}