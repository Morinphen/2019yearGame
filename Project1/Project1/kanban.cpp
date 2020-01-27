//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"kanban.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjkanban::CObjkanban(int x, int y, int t)
{
	m_x = x;
	m_y = y;
	type = t;
}

//�C�j�V�����C�Y
void CObjkanban::Init()
{
	num = 0.0f;
	flashing = false;

	hit_hero = false;

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KANBAN, 1);
	HitBox_ON = true;
}

//�A�N�V����
void CObjkanban::Action()
{
	//�\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//���j���[�p�̏��擾
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		if (scroll->Inscrooll_check(m_x, m_y) == true)
		{
			//�q�b�g�{�b�N�X����
			if (HitBox_ON == false)
			{
				HitBox_ON = true;
				Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_KANBAN, 1);
			}

			CHitBox* hit = Hits::GetHitBox(this);
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
				hit_hero = true;
			else
				hit_hero = false;

			m_scroll = scroll->GetScroll();
			l_scroll = scroll->GetYScroll();

			num++;
			if (num / 60 == 1)
			{
				num = 0.0f;
				flashing = flashing ? false : true;
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
}

//�h���[
void CObjkanban::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// �\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�Ŕ��g�傳����
		if(hit_hero==false)
		{
			//�u���b�N�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 512.0f;
			src.m_bottom = 512.0f;

			dst.m_top = m_y + l_scroll;
			dst.m_left = m_x + m_scroll;
			dst.m_right = dst.m_left + 64.0f;
			dst.m_bottom = dst.m_top + 64.0f;
			
			Draw::Draw(46, &src, &dst, c, 0.0f);
			
		}
		else
		{
			//�u���b�N�\��
			src.m_top = 0.0f;
			src.m_left = 0.0f;
			src.m_right = 512.0f;
			src.m_bottom = 512.0f;

			dst.m_top = m_y - 64.0f * 6 + l_scroll;
			dst.m_left = m_x - 64.0f * 3.5 + m_scroll;
			dst.m_right = dst.m_left + 64.0f * 8;
			dst.m_bottom = dst.m_top + 64.0f * 8;

			//�藠���Ŕ�
			if (type == 120)
			{
				if (flashing == false)
					Draw::Draw(47, &src, &dst, c, 0.0f);
				else
					Draw::Draw(48, &src, &dst, c, 0.0f);
			}
			//���[�h�`�F���W
			else if(type == 121)
			{
				if (flashing == false)
					Draw::Draw(49, &src, &dst, c, 0.0f);
				else
					Draw::Draw(50, &src, &dst, c, 0.0f);
			}
			//����
			else if (type == 122)
			{
				if (flashing == false)
					Draw::Draw(51, &src, &dst, c, 0.0f);
				else
					Draw::Draw(52, &src, &dst, c, 0.0f);
			}
			//�ؔ��R�₷
			else if (type == 123)
			{
				if (flashing == false)
					Draw::Draw(53, &src, &dst, c, 0.0f);
				else
					Draw::Draw(54, &src, &dst, c, 0.0f);
			}
			//�ǂ�ł�Ԃ�
			else if (type == 124)
			{
				if (flashing == false)
					Draw::Draw(55, &src, &dst, c, 0.0f);
				else
					Draw::Draw(56, &src, &dst, c, 0.0f);
			}
			//�y��
			else if (type == 125)
			{
				if (flashing == false)
					Draw::Draw(57, &src, &dst, c, 0.0f);
				else
					Draw::Draw(58, &src, &dst, c, 0.0f);
			}
			//�l�Y�~
			else if (type == 126)
			{
				if (flashing == false)
					Draw::Draw(59, &src, &dst, c, 0.0f);
				else
					Draw::Draw(60, &src, &dst, c, 0.0f);
			}
			//����
			else if (type == 127)
			{
				if (flashing == false)
					Draw::Draw(61, &src, &dst, c, 0.0f);
				else
					Draw::Draw(62, &src, &dst, c, 0.0f);
			}
			//����
			else if (type == 128)
			{
				if (flashing == false)
					Draw::Draw(63, &src, &dst, c, 0.0f);
				else
					Draw::Draw(64, &src, &dst, c, 0.0f);
			}
			//���o�[
			else if (type == 129)
			{
				if (flashing == false)
					Draw::Draw(65, &src, &dst, c, 0.0f);
				else
					Draw::Draw(66, &src, &dst, c, 0.0f);
			}
			//�W�����v
			else if (type == 115)
			{
				if (flashing == false)
					Draw::Draw(67, &src, &dst, c, 0.0f);
				else
					Draw::Draw(68, &src, &dst, c, 0.0f);
			}
		}
		
		
	}
}