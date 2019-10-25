//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;



//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	m_px = 200.0f;//�ʒu
	m_py = 500.0f;
	m_vx = 0.0f;//�ړ��x�N�g��
	m_vy = 0.0f;
	m_posture = 1.0f;//�E����0.0f�@������1.0f

	m_ani_time = 0;
	m_ani_frame = 1; //�Î~�t���[���������ɂ���

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 2;//�A�j���[�V�����Ԋu��

					   //block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;
	Hits::SetHitBox(this, m_vx, m_vy, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjEnemy::Action()
{
	//����
	if (m_py > 1000.0f)
	{
		;
	}

	//�ʏ푬�x
	m_speed_power = 0.5f;
	m_ani_max_time = 2;

	//����
	if (m_px<800)
	{
		m_vx += m_speed_power;
		m_posture = 1.0f;
		m_ani_time += 1;
	}
	/*else if (m_px>800)
	{
		m_vx -= m_speed_power;
		m_posture = 0.0f;
		m_ani_time += 1;
	}*/
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

	if (m_ani_frame == 2)
	{
		m_ani_frame = 0;
	}



	//���C
	m_vx += -(m_vx*0.098);

	//���R�����^��
    m_vy += 9.8 / (16.0f);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;

	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);
}

//�h���[
void CObjEnemy::Draw()
{
	int AniData[2] =
	{
		0,1,
	};

	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 65.0f;
	src.m_left = 448.0f*AniData[m_ani_frame]-64;
	src.m_right = 448.0f*AniData[m_ani_frame];
	src.m_bottom = 128.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = (64 - 64.0f*m_posture) + m_px;
	dst.m_right = (64.0f*m_posture) + m_px;
	dst.m_bottom = 64.0f + m_py;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}
