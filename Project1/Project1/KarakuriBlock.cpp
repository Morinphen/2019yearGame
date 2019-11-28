//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"KarakuriBlock.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjKarakuriblock::CObjKarakuriblock(int x, int y, int n)
{
	m_x = x;
	m_y = y;
	num = n - 3;
}

//�C�j�V�����C�Y
void CObjKarakuriblock::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
	Delete = false;
	HitBox_ON=true;
	Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, num, 1);
}

//�A�N�V����
void CObjKarakuriblock::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�q�b�g�{�b�N�X����
		if (HitBox_ON == false)
		{
			HitBox_ON = true;
			Hits::SetHitBox(this, m_x, m_y + 48, 64, 64, ELEMENT_BLACK, num, 1);
		}
		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();

		CHitBox* hit = Hits::GetHitBox(this);
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
	//���o�[���N�������玩��������
	if (Delete == true)
	{
		CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		pb->Deletemap(m_x, m_y);
		Hits::DeleteHitBox(this);
		this->SetStatus(false);
	}

}

//�h���[
void CObjKarakuriblock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	// �\����ʓ��̎�
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{
		//�u���b�N�\��
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;

		dst.m_top = m_y + l_scroll;
		dst.m_left = m_x + m_scroll;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = dst.m_top + 64.0f;

		Draw::Draw(26, &src, &dst, c, 0.0f);
	}
}