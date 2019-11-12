//�g�p����w�b�_�[�t�@�C��
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Dondengaesi.h"
#include"GameL\HitBoxManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjDonden::CObjDonden(int x, int y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjDonden::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//�Î~�t���[��������

	red = 1.0f;
	Wanimation = false;
	Wanimation2 = false;
	s_down = false;

	m_speed_power = 0.5f;//�ʏ푬�x
	m_ani_max_time = 4;//�A�j���[�V�������o��

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_DONDEN, 1);
}
//�A�N�V����
void CObjDonden::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

	s_down = h->GetDown();

	int a = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (scroll->m_map[i][j] == 5)
			{
				D_tag[a][0] = i;
				D_tag[a][1] = j;
				a++;
			}
		}
	}

	Pworp = Worp((a));
	
	//��l�����G�ꂽ�Ƃ�
	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		red = 0.0f;
		bool stop;
		stop = h->GetNawa();
		//�����͂����ꂽ�Ƃ��A�A�j���[�V�������J�n
		if (Input::GetVKey(VK_UP) == true && s_down == true && stop==false)
		{
			if (h->Sworp == false && Wanimation == false && Wanimation2 == false) {

				h->W_cat = 0.0f;
				h->W_cat2 -= 6.4f;
				h->Sworp = true;

				Wanimation = true;
			}
		}
	}

	else
	{
		red = 1.0f;
	}

	//�A�j���[�V�����O���J�n��
	if (Wanimation == true)
	{
		//��l�����A�j���[�V���������A���[�v���Ă��鈵���ɕύX
		h->W_cat2 -= 6.4f;
		h->Sworp = true;
		//���̃A�j���[�V�������I������Ƃ�
		if (h->W_cat2 <= -64.0f)
		{
			//��l���̍��W�����[�v��ɕύX
			h->SetX(D_tag[Pworp][1] * 64);
			h->SetY(D_tag[Pworp][0] * 64);

			//��l���̃��X�^�[�g�ʒu�ύX
			h->SetWX(D_tag[Pworp][1] * 64);
			h->SetWY(D_tag[Pworp][0] * 64);

			scroll->SetScrooll(-(h->GetX() - (400)));
			if (h->GetY() < 80) {
				scroll->SetYScrooll(-(h->GetY() - (80)));
			}
			else if (h->GetY() > 500) {
				scroll->SetYScrooll(-(h->GetY() - (500)));
			}

			//�A�j���[�V�����㔼�J�n
			h->W_cat2 = -64.0f;
			Wanimation = false;
			Wanimation2 = true;
		}
	}

	//�A�j���[�V�����㔼�J�n��
	if (Wanimation2 == true)
	{
		h->W_cat2 += 6.4f;
		h->Sworp = true;
		//�A�j���[�V�������I������Ƃ�
		if (h->W_cat2 >= 0.0f) {
			h->W_cat2 = 0.0f;
			h->W_cat = 1.0f;
			Wanimation2 = false;
		}
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//�h���[
void CObjDonden::Draw()
{
	float c[4] = { 1.0f,red,red,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 64.0f;

	dst.m_top = m_y + l_scroll;
	dst.m_left = m_x + m_scroll;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	Draw::Draw(5, &src, &dst, c, 0.0f);
}

//�ǂ�ł�Ԃ��̃^�b�O�����߂�֐�
int CObjDonden::Worp(int a)
{
	int data[10];
	int data2[10];

	int base;
	int aa = 0;

	//�ǂ�ł�Ԃ�������ꏊ�̃f�[�^��ۑ�
	for (int i = 0; i < a ; i++)
	{
		if ((D_tag[i][0] * 64) != m_y || (D_tag[i][1] * 64) != m_x) {
			data[aa] = D_tag[i][0] + D_tag[i][1];
			data2[aa] = i;
			aa++;
		}
		else
			base = D_tag[i][0] + D_tag[i][1];
	}

	//�ǂ�ł�Ԃ��̋��������߂邽�߁A��Βl��
	for (int i = 0; i < aa; i++) {
		data[i] = abs(data[i] - base);
	}

	//�o�u���\�[�g
	for (int i = 0; i < aa - 1; i++)
	{
		for (int j = aa - 1; j > i; j--)
		{
			//���g�ɍł��߂��ǂ�ł�Ԃ��̈ʒu�𒲂ׁA�\�[�g������
			if (data[j] < data[j - 1])
			{
				int a = data[j - 1];
				data[j - 1] = data[j];
				data[j] = a;

				a = data2[j - 1];
				data2[j - 1] = data2[j];
				data2[j] = a;
			}
		}
	}

	return data2[0];
}