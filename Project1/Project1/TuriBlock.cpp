//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include "TuriBlock.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjTBlock::CObjTBlock(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjTBlock::Init()
{
	m_ani_frame = 0;
	m_ani_time = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;

	modecheck = false;//���[�h�ؑ�

	Hits::SetHitBox(this, m_x, m_y, 64, 576, ELEMENT_BLACK, OBJ_TURIBLOCK, 1);
}
//�A�N�V����
void CObjTBlock::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	CObjBlock* block= (CObjBlock*)Objs::GetObj(OBJ_TURIBLOCK);
	

	//�v�f�ԍ������U�ɕύX
	float x = m_x;
	float y = m_y;

	

	/*m_ani_time++;
	if (m_ani_time == 16)
	{
		m_ani_time = 0;
		m_ani_frame++;
		if (m_ani_frame == 4)
		{
			m_ani_frame = 0;
		}
	}*/

	aaa++;
	CHitBox* hit = Hits::GetHitBox(this);

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		//��l���Ɠ���������t���O���I����
		modecheck = true;
		
		Hits::DeleteHitBox(this);
		Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_BLACK, OBJ_TURIBLOCK2, 1);
	}

	if (modecheck == true)
	{
		m_y += 5;
	
		
	}


	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//�h���[
void CObjTBlock::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	////�u���b�N�\��
	//src.m_top = 0.0f;
	//src.m_left = 0.0f + (m_ani_frame*64.0f);
	//src.m_right = 64.0f + (m_ani_frame*64.0f);
	//src.m_bottom = 64.0f;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;
	Draw::Draw(14, &src, &dst, c, 0.0f);
}