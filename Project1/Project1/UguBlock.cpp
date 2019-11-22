//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"HonoBlock.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjUguBlock::CObjUguBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjUguBlock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	uguisu = false;

	m_ani_time = 0;
	m_ani_frame = 0;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_UGUBLOCK, 1);
	HitBox_ON = true;
}
//�A�N�V����
void CObjUguBlock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�q�b�g�{�b�N�X����
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_UGUBLOCK, 1);
		}

		//��l���̈ʒu���擾
		CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
		float hx = hero->GetX();
		float hy = hero->GetY();

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
					uguisu = true;
					hero->Dflag(true);
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

		CHitBox* hit = Hits::GetHitBox(this);

		if (uguisu == true)
		{
			m_ani_time++;
			if (m_ani_time == 6) {
				m_ani_time = 0;
				m_ani_frame++;
			}

		}

		if (m_ani_frame == 12)
		{
			Audio::Stop(0);
			Scene::SetScene(new CSceneMain);
		}

		hit->SetPos(m_x + m_scroll, m_y + l_scroll);
	}
	//�\����ʊO�̎�
	else
	{
		//�q�b�g�{�b�N�X�폜
		if (HitBox_ON == true)
		{
			HitBox_ON = false;
			Hits::DeleteHitBox(this);
		}
	}
}

//�h���[
void CObjUguBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�u���b�N�\��
		src.m_top = 0.0f + ((m_ani_frame % 4)*64.0f);
		src.m_left = 64.0f * 4;
		src.m_right = 64.0f * 5;
		src.m_bottom = 64.0f + ((m_ani_frame % 4)*64.0f);

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(0, &src, &dst, c, 0.0f);
		if (uguisu == true)
			Draw::Draw(13, &src, &dst, c, 0.0f);
	}
}