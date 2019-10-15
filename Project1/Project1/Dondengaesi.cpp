//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Dondengaesi.h"
#include"GameL\HitBoxManager.h"

//使用するネームスペース
using namespace GameL;

CObjDonden::CObjDonden(int x, int y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjDonden::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	red = 1.0f;

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_DONDEN, 1);
}
//アクション
void CObjDonden::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	m_scroll = scroll->GetScroll();
	l_scroll = scroll->GetYScroll();

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

	Worp((a));

	if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
	{
		red = 0.0f;
	}

	else
	{
		red = 1.0f;
	}

	hit->SetPos(m_x + m_scroll, m_y + l_scroll);
}
//ドロー
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

	Draw::Draw(4, &src, &dst, c, 0.0f);
}

int CObjDonden::Worp(int a)
{
	int data[10];

	int base;

	//どんでん返しがある場所のデータを保存
	for (int i = 0; i < a; i++)
	{
		if(D_tag[i][0] * 64 != m_y&&D_tag[i][1] * 64 != m_x)
			data[i] = D_tag[i][0] + D_tag[i][1];
		else
			base = D_tag[i][0] + D_tag[i][1];
	}

	//バブルソート
	for (int i = 0; i < a - 1; i++)
	{
		data[i] = abs(data[i] - base);
		for (int j = a - 1; j > i; j--)
		{
			if (data[j] < data[j - 1])
			{
				int a = data[j - 1];
				data[j - 1] = data[j];
				data[j] = a;
			}
		}
	}

	return data[0];
}