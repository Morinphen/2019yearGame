//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

#include"GameHead.h"
#include"Fireenemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjFireEnemy::CObjFireEnemy(int x, int y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjFireEnemy::Init()
{
	m_vx = 0.0f;//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;//�E����0.0f�@������1.0f
	m_posture_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1; //�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�����Ԋu��

	m_move = true;    //true=���@false=�E

	find = false;
					  //block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	crhitbox = true;
	de = false;
	stop=false;
}

//�A�N�V����
void CObjFireEnemy::Action()
{
	if (crhitbox == true && m_move == true)
	{
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_px, m_py, 192, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
		crhitbox = false;
	}
	else if (crhitbox == true && m_move == false)
	{
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_px, m_py, 192, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
		crhitbox = false;
	}

	//�u���b�N�Ƃ̓����蔻��
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	CObjHero* hr = (CObjHero*)Objs::GetObj(OBJ_HERO);
	pb->BlockHit(&m_px, &m_py, false, true,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, false,
		&m_vx, &m_vy
	);


	//�u���b�N�Փ˂Ō�����ύX
	if (m_hit_left == true && m_hit_right == false || m_posture_time>150 && m_move == false)
	{
		m_move = true;
		crhitbox = true;
		m_posture_time = 0;
	}

	if (m_hit_right == true && m_hit_left == false || m_posture_time>150 && m_move == true)
	{
		m_move = false;
		crhitbox = true;
		m_posture_time = 0;
	}
	//�ʏ푬�x
	m_speed_power = 0.3f;
	m_ani_max_time = 4;
	CHitBox* hit = Hits::GetHitBox(this);
	if (find==false && stop == false)
	{
		//����
		if (m_move == false)
		{
			m_vx += m_speed_power;
			m_posture = 1.0f;
			m_ani_time += 1;
		}

		else if (m_move == true)
		{
			m_vx -= m_speed_power;
			m_posture = 0.0f;
			m_ani_time += 1;
		}

		else
		{
			m_ani_frame = 1;
			m_ani_time = 0;
		}

		if (m_ani_time > m_ani_max_time)
		{
			m_ani_frame += 1;
			m_ani_time = 0;
		}

		if (m_ani_frame == 4)
		{
			m_ani_frame = 0;
		}

		m_posture_time += 1;
		//���C
		m_vx += -(m_vx*0.098);

		//���R�����^��
		m_vy += 9.8 / (16.0f);

		//�ʒu�̍X�V
		m_px += m_vx;
		m_py += m_vy;

	}
	if (hit->CheckObjNameHit(OBJ_HERO) == nullptr&&find == true)
	{
		find = false;
	}
	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	if (m_move == true)
	{
		hit->SetPos(m_px + block->GetScroll() - 128, m_py + block->GetYScroll());
	}
	else if (m_move == false)
	{
		hit->SetPos(m_px + block->GetScroll(), m_py + block->GetYScroll());
	}
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr&&find == false && hr->Getsmoke_h() == false)
	{
		find = true;
		hr->Dflag_s(true);
	}
	if (hit->CheckObjNameHit(OBJ_HINOTAMA) != nullptr)
	{
		CObjHinotama* sa = (CObjHinotama*)Objs::GetObj(OBJ_HINOTAMA);
		sm_x = sa->GetX();
		p = sa->GetP();
		if (m_move == true)//�G������
		{
			if (p == true)//�藠��������
			{
				Audio::Start(14);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				sa->SetT(true);
			}
			else//�藠���E����
			{
				if (sm_x + 2.0 >= m_px)
				{
					Audio::Start(14);
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
					sa->SetT(true);
				}
			}
		}
		else//�G�E����
		{
			if (p == true)//�藠��������
			{
				if (sm_x - 2.0 <= m_px)
				{
					Audio::Start(14);
					this->SetStatus(false);
					Hits::DeleteHitBox(this);
					sa->SetT(true);
				}
			}
			else//�藠���E����
			{
				Audio::Start(14);
				this->SetStatus(false);
				Hits::DeleteHitBox(this);
				sa->SetT(true);
			}
		}
	}
}

//�h���[
void CObjFireEnemy::Draw()
{
	int AniData[4] =
	{
		0,1,0,1,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src.m_top = 321.0f;
	src.m_left = 64.0f*AniData[m_ani_frame];
	src.m_right = 64.0f*AniData[m_ani_frame]+64;
	src.m_bottom = 384.0f;

	//�u���b�N���������Ă���
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py + scroll->GetYScroll();
	dst.m_left = (64 - 64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_right = (64.0f*m_posture) + m_px + scroll->GetScroll();
	dst.m_bottom = 64.0f + m_py + scroll->GetYScroll();

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);

	RECT_F srcs; //�`�挳�؂���ʒu
	RECT_F dsts; //�`���\���ʒu
	if (m_move == true)
	{
		srcs.m_top = 0.0f;
		srcs.m_left = 0.0f;
		srcs.m_right = 300.0f;
		srcs.m_bottom = 300.0f;
		//�\���ʒu�̐ݒ�
		dsts.m_top = dst.m_top;
		dsts.m_left = dst.m_left - 230.0f;
		dsts.m_right = dst.m_right + 64;
		dsts.m_bottom = dst.m_bottom;
	}
	else
	{
		srcs.m_top = 0.0f;
		srcs.m_left = 300.0f;
		srcs.m_right = 0.0f;
		srcs.m_bottom = 300.0f;
		//�\���ʒu�̐ݒ�
		dsts.m_top = dst.m_top;
		dsts.m_left = dst.m_left;
		dsts.m_right = dst.m_right + 166.0f;
		dsts.m_bottom = dst.m_bottom;
	}
	//�`��
	Draw::Draw(28, &srcs, &dsts, c, 0.0f);
 if(find==true)
 {
	RECT_F src_h;
	RECT_F dst_h;
	src_h.m_top = 0.0f;
	src_h.m_left = 0.0f;
	src_h.m_right = 32.0f;
	src_h.m_bottom = 32.0f;

	//�\���ʒu�̐ݒ�
	dst_h.m_top = dst.m_top-64.0f;
	dst_h.m_left = dst.m_left;
	dst_h.m_right = dst.m_right;
	dst_h.m_bottom = dst.m_bottom-64.0f;

	Draw::Draw(34, &src_h, &dst_h, c, 0.0f);
 }
}