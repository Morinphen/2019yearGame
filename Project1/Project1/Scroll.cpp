//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include"GameL\SceneObjManager.h"
#include"GameHead.h"
#include"Scroll.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjScroll::Init()
{
	m_scroll = 0.0f;
	l_scroll = 0.0f;
}
//�A�N�V����
void CObjScroll::Action()
{
	//��l���̈ʒu���擾
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();

	//����X�N���[�����C��
	if (hx < 80)
	{
		hero->SetX(80);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	//�O���X�N���[�����C��
	if (hx > 300)
	{
		hero->SetX(300);//��l���̓��C���𒴂��Ȃ��悤��
		m_scroll -= hero->GetVX();//��l�����{������������������
	}

	//����X�N���[�����C��
	if (hy < 80)
	{
		hero->SetY(80);//��l���̓��C���𒴂��Ȃ��悤��
		l_scroll -= hero->GetVY();//��l�����{������������������
	}

	//�����X�N���[�����C��
	if (hy > 500 && l_scroll>-100)
	{
		hero->SetY(500);//��l���̓��C���𒴂��Ȃ��悤��
		l_scroll -= hero->GetVY();//��l�����{������������������
	}

	//��l���̏Փˏ�Ԋm�F�p�׸ނ̏�����
	hero->SetUP(false);
	hero->SetDown(false);
	hero->SetLeft(false);
	hero->SetRight(false);

}
//�h���[
void CObjScroll::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	//�w�i�\��
	src.m_top = 300.0f - (l_scroll / 4);
	src.m_left = 100.0f - (m_scroll / 4);
	src.m_right = 700.0f - (m_scroll / 4);
	src.m_bottom = 1000.0f - (l_scroll / 4);
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 800.0f;
	Draw::Draw(2, &src, &dst, c, 0.0f);
}