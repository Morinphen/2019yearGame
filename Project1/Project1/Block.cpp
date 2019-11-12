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

CObjBlock::CObjBlock(int map[46][100])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int)*(46 * 100));
}

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	aaa = 0;
	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_BLOCK, 1);
}
//�A�N�V����
void CObjBlock::Action()
{
	
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();



}
//�h���[
void CObjBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			//�u���b�N�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 64.0f;
			src.m_bottom = 64.0f;

			dst.m_top = i*64.0f + l_scroll;
			dst.m_left = j*64.0f + m_scroll;
			dst.m_right = dst.m_left + 64.0f;
			dst.m_bottom = dst.m_top + 64.0f;

			if (m_map[i][j] == 1)
			{
				Draw::Draw(1, &src, &dst, c, 0.0f);
			}
		}
	}
}


//�u���b�N�Ƃ̓����蔻��֐�(BlockHit�֐�)
//����1  float* x          ;������s��object��x�ʒu
//����2  float* y          ;������s��object��y�ʒu
//����3  bool*  up         ;�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����4  bool*  down       ;�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����5  bool*  left       ;�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����6  bool*  right      ;�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����7  bool   smoke      ;���ʂ��𔻒肷��(true:����)
//����8  float* vx         ;���E���莞�̔����ɂ��ړ������E�͂̒l�ς��ĕԂ�
//����9  float* vy         ;�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//������s��object�ƃu���b�N64��64����ŁA�����蔻��Ə㉺���E������s��
//���̌��ʂ͈���3�`8�ɕԂ�
void CObjBlock::BlockHit
(
	float* x, float* y, bool s,
	bool*up, bool* down, bool* left, bool* right,bool smoke,
	float *vx, float *vy
)
{
	//��l���̏Փˊm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] == 1)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;

				float m_s=0;
				float l_s=0;

				if (s == true)
				{
					CObjScroll * scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
					m_s = scroll->GetScroll();
					l_s = scroll->GetYScroll();
				}

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-m_s) + 64.0f > bx) && (*x + (-m_s)<bx + 64.0f) && (*y + (-l_s) + 64.0f>by) && (*y + (-l_s)<by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-m_s)) - bx;
					float rvy = (*y + (-l_s)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy * rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						//���ʂ�����
						if (smoke == false)
						{
							//�p�x�ŏ㉺���E�𔻒�
							if ((r < 45 && r>0) || r > 315)
							{
								//�E
								*right = true;//��l���̍��̕������Փ˂��Ă��邩
								*x = bx + 64.0f + (m_s);//�u���b�N�Ɉʒu-��l���̕�
								*vx = -(*vx)*0.1f;//-VX*�����W��
							}

							if (r > 45 && r < 135)
							{
								//��
								*down = true;//��l���̉��̕������Փ˂��Ă��邩
								*y = by - 64.0f + (l_s);//�u���b�N�Ɉʒu-��l���̕�
								*vy = 0.0f;
							}

							if (r > 135 && r < 225)
							{
								//��
								*left = true;//��l���̉E�̕������Փ˂��Ă��邩
								*x = bx - 64.0f + (m_s);//�u���b�N�Ɉʒu-��l���̕�
								*vx = -(*vx)*0.1f;//-VX*�����W��
							}

							if (r > 225 && r < 315)
							{
								//��
								*up = true;//��l���̏�̕������Փ˂��Ă��邩
								*y = by + 64.0f + (l_s);//�u���b�N�̈ʒu+��l���̕�
								if (*vy < 0)
								{
									*vy = 0.0f;
								}
							}
						}
						else
						{
							//�p�x�ŏ㉺���E�𔻒�
							if ((r < 45 && r>0) || r > 315)
							{
								//�E
								*right = true;//���ʂ̍��̕������Փ˂��Ă��邩
								*x = bx + 64.0f + (m_s);//�u���b�N�Ɉʒu-���ʂ̕�
								*vx = -(*vx)*0.0f;//-VX*�����W��
							}

							if (r > 45 && r < 135)
							{
								//��
								*down = true;//��l���̉��̕������Փ˂��Ă��邩
								*y = by - 64.0f + (l_s);//�u���b�N�Ɉʒu-��l���̕�
								*vy = 0.0f;
								CObjSmokeball* smokeball = (CObjSmokeball*)Objs::GetObj(OBJ_SMOKEBALL);
								smokeball->Setmodecheck(true);
							}

							if (r > 135 && r < 225)
							{
								//��
								*left = true;//���ʂ̉E�̕������Փ˂��Ă��邩
								*x = bx - 64.0f + (m_s);//�u���b�N�Ɉʒu-���ʂ̕�
								*vx = -(*vx)*0.0f;//-VX*�����W��
							}

							if (r > 225 && r < 315)
							{
								//��
								*up = true;//���ʂ̏�̕������Փ˂��Ă��邩
								*y = by + 64.0f + (l_s);//�u���b�N�̈ʒu+���ʂ̕�
								if (*vy < 0)
								{
									*vy = 0.0f;
								}
							}
						}
					}
				}
			}
		}
	}
}

void CObjBlock::UBlockHit
(
	float* x, float* y, bool* flag,
	bool*up, bool* down, bool* left, bool* right,
	float *vx, float *vy
)
{
	//��l���̏Փˊm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m_map[i][j] != 7)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*64.0f;
				float by = i*64.0f;

				//�I�u�W�F�N�g�ƃu���b�N�̓����蔻��
				if ((*x + (-m_scroll) + 64.0f > bx) && (*x + (-m_scroll) < bx + 64.0f) && (*y + (-l_scroll) + 64.0f > by) && (*y + (-l_scroll) < by + 64.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = (*x + (-m_scroll)) - bx;
					float rvy = (*y + (-l_scroll)) - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy * rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);

					else
						r = 360.0f - abs(r);

					//len��������̒����̂��Z���ꍇ����ɓ���
					if (len < 88.0f)
					{
						CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r>=0) || r > 315)
						{
							//�E
							*right = true;//��l���̍��̕������Փ˂��Ă��邩
							*x = bx + 64.0f + (m_scroll);//�u���b�N�Ɉʒu-��l���̕�

							if (*flag == false)
							{
								scroll->SetScrooll(m_scroll - 64);
								*flag = true;
							}
							else
							{
								*vx = -(*vx)*0.0f;//-VX*�����W��
							}
						}

						//if (r > 45 && r < 135)
						//{
						//	//��
						//	*down = true;//��l���̉��̕������Փ˂��Ă��邩
						//	*y = by - 64.0f + (l_scroll);//�u���b�N�Ɉʒu-��l���̕�
						//	*vy = 0.0f;
						//}

						if (r > 135 && r < 225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă��邩

							if (*flag == false)
							{
								scroll->SetScrooll(m_scroll + 64);
								*flag = true;
							}

							else
							{
								*vx = -(*vx)*0.0f;//-VX*�����W��
							}

							*x = bx - 64.0f + (m_scroll);//�u���b�N�Ɉʒu-��l���̕�
						}
					}
				}
			}
		}
	}
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