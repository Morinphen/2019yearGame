//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Dsyuriken.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjDsyuriken::CObjDsyuriken(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjDsyuriken::Init()
{
	deadtime = 0;
	m_scroll = 0.0f;
	l_scroll = 0.0f;

}
//�A�N�V����
void CObjDsyuriken::Action()
{
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	//���j���[�p�̏��擾
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		m_scroll = scroll->GetScroll();
		l_scroll = scroll->GetYScroll();
		deadtime += 1;
		if (deadtime == 100)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}
	}
}
//�h���[
void CObjDsyuriken::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,(1.0f - deadtime / 100) };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0;
	src.m_right = 346.0f;
	src.m_bottom = 512.0f;
	//�u���b�N���������Ă���
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	dst.m_top = (0.0f + m_y - 64 + scroll->GetYScroll()) + (64 * (1 - deadtime / 120));
	dst.m_bottom = (64.0f + m_y - 64 + scroll->GetYScroll()) + (64 * (1 - deadtime / 120));
	dst.m_left = (64.0f+m_x + scroll->GetScroll());
	dst.m_right = (64.0f - 64.0f+ m_x + scroll->GetScroll());
	Draw::Draw(43, &src, &dst, c, 0.0f);

}