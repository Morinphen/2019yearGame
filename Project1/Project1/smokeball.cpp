//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"smokeball.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjSmokeball::CObjSmokeball(int x, int y, int m)
{
	m_x = x;
	m_y = y;
	m_muki = -m;

	if (m == 0) {
		m_muki = 1;
	}
}

//�C�j�V�����C�Y
void CObjSmokeball::Init()
{
	m_vx = 9 * m_muki;
	m_vy = -9;
	m_posture = 1.0f;//�E����0.0���A������1.0f

	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[��������

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�������o��

	smokeball_delete = false;//�폜����

	modecheck = false;//���[�h�ؑ�

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_PLAYER, OBJ_SYURIKEN, 1);
}

//�A�N�V����
void CObjSmokeball::Action()
{
	//�ʂ̏��
	if (modecheck == false)
	{

		//�u���b�N�Ƃ̓����蔻��
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->BlockHit(&m_x, &m_y,true,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right, true,
			&m_vx, &m_vy
		);

		m_x += m_vx;
		m_y += m_vy;

		//�d��
		if (m_vy < 20)
			m_vy += 9.8f / 16.0f;

	}
	//���̏��
	else
	{
		smoke_time++;
		if (smoke_time / 60 == 5)
		{
			modecheck = false;
			smoke_time = 0;
			smokeball_delete = true;
		}
	}

	hit = Hits::GetHitBox(this);

	//��l�����擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�폜����
	if (smokeball_delete == true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		hero->SetBallFlag(false);
	}

	//�폜�͈�
	if (m_y > 800)
		smokeball_delete = true;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	hit->SetPos(m_x + block->GetScroll(), m_y);
}
//�h���[
void CObjSmokeball::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�ʂ̏��
	if (modecheck == false)
	{
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = 0.0f + m_y;
		dst.m_left = 0.0f + m_x;
		dst.m_right = 64.0f + m_x;
		dst.m_bottom = 64.0f + m_y;

		Draw::Draw(6, &src, &dst, c, 0);
	}
	//���̏��
	else
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = -4; j < 5; j++)
			{
				src.m_top = 0.0f;
				src.m_left = 0.0f;
				src.m_right = 200.0f;
				src.m_bottom = 200.0f;

				dst.m_top = (0.0f + m_y)-(64.0f*i);
				dst.m_left = (0.0f*m_posture + m_x)+(64.0f*j) + block->GetScroll();
				dst.m_right = (64.0f*m_posture + m_x)+(64.0f*j) + block->GetScroll();
				dst.m_bottom = (64.0f + m_y)-(64.0f*i);

				Draw::Draw(1, &src, &dst, c, 0);
			}
		}
	}
}