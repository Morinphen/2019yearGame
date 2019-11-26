//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"MizuBlock.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjMBlock::CObjMBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjMBlock::Init()
{
	m_ani_frame = 0;
	m_ani_time = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	h_flag = false;
	deadtime = 0;
	Fdead = false;
	Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, OBJ_MIZUBLOCK, 1);
}
//�A�N�V����
void CObjMBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	h_flag = hero->GetMode();

	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	//�㉺���E����
	float x = m_x;
	float y = m_y;

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
	if (len < 88.0f && h_flag == true) {
		//�p�x�ŏ㉺���E�𔻒�
		if ((r < 45 && r >= 0) || r > 315)
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

	//�q�b�g�{�b�N�X�X�V
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr && Fdead == false)
	{
		Fdead = true;
		hero->WDflag(true);
	}

	//��l�������������Ƃ�
	if (Fdead == true)
	{
		hero->SetVX(0);
		hero->SetVY(0);
		deadtime++;
		//��l���𒆊ԃ|�C���g�ɖ߂�
		if (deadtime == 79)
		{
			hero->SetX(hero->GetWX());
			hero->SetY(hero->GetWY());

			scroll->SetScrooll(-(hero->GetX() - (400)));
			if (hero->GetY() < 80) {
				scroll->SetYScrooll(-(hero->GetY() - (80)));
			}
			else if (hero->GetY() > 500) {
				scroll->SetYScrooll(-(hero->GetY() - (500)));
			}

		}
		//��l���̃~�X��������Z�b�g
		if (deadtime == 80)
		{
			deadtime = 0;
			Fdead = false;
			hero->WDflag(false);
			hero->Dflag(false);
		}

	}

	m_ani_time++;
	if (m_ani_time == 16)
	{
		m_ani_time = 0;
		m_ani_frame++;
		if (m_ani_frame == 4)
		{
			m_ani_frame = 0;
		}
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll + 48);
}
//�h���[
void CObjMBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�u���b�N�\��
	src.m_top = 0.0f;
	src.m_left = 0.0f + (m_ani_frame*64.0f);
	src.m_right = 64.0f + (m_ani_frame*64.0f);
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(14, &src, &dst, c, 0.0f);
}