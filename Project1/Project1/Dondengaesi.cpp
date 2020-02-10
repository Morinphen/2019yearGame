//使用するヘッダーファイル
#include"GameL\DrawTexture.h"
#include"GameL\WinInputs.h"
#include"GameHead.h"
#include"Dondengaesi.h"
#include"GameL\HitBoxManager.h"
#include"GameL\Audio.h"
#include"main.h"

//使用するネームスペース
using namespace GameL;

//ゲームパッド用
XINPUT_STATE d_state;

CObjDonden::CObjDonden(int x, int y, int namber, bool b)
{
	m_x = x;
	m_y = y;
	hide = b;
	Wnamber = namber;
}

//イニシャライズ
void CObjDonden::Init()
{
	m_ani_time = 0;
	m_ani_frame = 1;//静止フレーム初期化

	red = 1.0f;
	Wanimation = false;
	Wanimation2 = false;
	s_down = false;
	N_stop = false;

	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	int a = 0;
	for (int i = 0; i < 46; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (scroll->m_map[i][j] >= 30  && scroll->m_map[i][j] <= 50)
			{
				D_tag[a][0] = i;
				D_tag[a][1] = j;
				D_tag[a][2] = scroll->m_map[i][j];
				a++;
			}
			else if (scroll->m_map[i][j] == 12)
			{
				D_tag[a][0] = i;
				D_tag[a][1] = j;
				D_tag[a][2] = scroll->m_map[i][j];
				a++;
			}
		}
	}

	Pworp = TagWorp((a));

	m_speed_power = 0.5f;//通常速度
	m_ani_max_time = 4;//アニメーション感覚幅

	Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_DONDEN, 1);
	HitBox_ON = true;
}
//アクション
void CObjDonden::Action()
{
	//ゲームパッド用
	DWORD dwResult = XInputGetState(0, &d_state);

	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	//表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);

	//メニュー用の情報取得
	CObjMany* mn = (CObjMany*)Objs::GetObj(OBJ_MANY);
	bool m_stop = mn->GetOpen();

	if (m_stop == false) {
		if (scroll->Inscrooll_check(m_x, m_y) == true)
		{
			//ヒットボックス生成
			if (HitBox_ON == false)
			{
				HitBox_ON = true;
				Hits::SetHitBox(this, m_x, m_y, 64, 64, ELEMENT_ITEM, OBJ_DONDEN, 1);
			}

			CHitBox* hit = Hits::GetHitBox(this);

			m_scroll = scroll->GetScroll();
			l_scroll = scroll->GetYScroll();

			//主人公の状態を持ってくる
			s_down = h->GetDown();
			N_stop = h->GetINawa();

		//種類確認
		if (hide == false || hide == true && h->GetDoton() == true)
		{
			//主人公が触れたとき
			if (hit->CheckObjNameHit(OBJ_HERO) != nullptr)
			{
				red = 0.0f;
				bool stop;//投げ縄を投げていないかどうか確認
				bool hamustop;//鼠が出ていないか確認
				stop = h->GetNawa();
				hamustop = h->GetHamu();
				//↑入力をされたとき、アニメーションを開始
				if (Input::GetVKey(VK_UP) == true && s_down == true && stop == false && N_stop == false||
					d_state.Gamepad.sThumbLY > XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE&& s_down == true && 
					stop == false && N_stop == false && hamustop==false)
				{
					if (h->Sworp == false && Wanimation == false && Wanimation2 == false) {
						Audio::Start(4);
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
			}

			//アニメーション前半開始時
			if (Wanimation == true)
			{
				//主人公をアニメーションさせ、ワープしている扱いに変更
				h->W_cat2 -= 6.4f;
				h->Sworp = true;
				//一定のアニメーションが終わったとき
				if (h->W_cat2 <= -64.0f)
				{
					//主人公の座標をワープ先に変更
					h->SetX(D_tag[Pworp][1] * 64);
					h->SetY(D_tag[Pworp][0] * 64);

					//主人公のリスタート位置変更
					h->SetWX(D_tag[Pworp][1] * 64);
					h->SetWY(D_tag[Pworp][0] * 64);

					scroll->SetScrooll(-(h->GetX() - (D_tag[Pworp][1] * 64)));
					scroll->SetYScrooll(-(h->GetY() - (D_tag[Pworp][0] * 64)));

					int a = D_tag[Pworp][0] * 64;

					scroll->Donden_check(h->GetX(), h->GetY());


					////前方スクロールライン
					if (h->GetX() > 600)
					{
						scroll->SetScrooll(-(h->GetX() - (600)));
						h->SetX(600);
					}

					else if (h->GetX() < 500)
					{
						scroll->SetScrooll(-(h->GetX() - (500)));
						h->SetX(500);
					}

					//if (h->GetY() < 80) {
					//	scroll->SetYScrooll(-(h->GetY() - (80)));
					//	h->SetY(80);
					//}
					//else if (h->GetY() > 500) {
					//	scroll->SetYScrooll(-(h->GetY() - (500)));
					//	h->SetY(500);
					//}

					//アニメーション後半開始
					h->W_cat2 = -64.0f;
					Wanimation = false;
					Wanimation2 = true;
				}
			}

			hit->SetPos(m_x + m_scroll, m_y + l_scroll);
		}
		//表示画面外の時
		else
		{
			//ヒットボックス削除
			if (HitBox_ON == true)
			{
				HitBox_ON = false;
				Hits::DeleteHitBox(this);
			}
		}

		//アニメーション後半開始時
		if (Wanimation2 == true)
		{
			h->W_cat2 += 6.4f;
			h->Sworp = true;
		}

		//アニメーションが終わったとき
		if (h->W_cat2 >= 0.0f) {
			h->W_cat2 = 0.0f;
			h->W_cat = 1.0f;
			Wanimation2 = false;
		}
	}
}
//ドロー
void CObjDonden::Draw()
{
	CObjHero* h = (CObjHero*)Objs::GetObj(OBJ_HERO);

	// 表示画面内の時
	CObjScroll* scroll = (CObjScroll*)Objs::GetObj(OBJ_SCROLL);
	if (scroll->Inscrooll_check(m_x, m_y) == true)
	{

		if (hide == false || hide == true && h->GetDoton() == true)
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
	}
}

//どんでん返しのタッグを決める関数
int CObjDonden::Worp(int a)
{
	int data[50];
	int data2[50];

	int base;
	int aa = 0;

	//どんでん返しがある場所のデータを保存
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

	//どんでん返しの距離を求めるため、絶対値化
	for (int i = 0; i < aa; i++) {
		data[i] = abs(data[i] - base);
	}

	//バブルソート
	for (int i = 0; i < aa - 1; i++)
	{
		for (int j = aa - 1; j > i; j--)
		{
			//自身に最も近いどんでん返しの位置を調べ、ソートさせる
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

int CObjDonden::TagWorp(int a)
{
	int data[50];
	int data2[50];
	int data3[50];

	int base;
	int aa = 0;

	//どんでん返しがある場所のデータを保存
	for (int i = 0; i < a; i++)
	{
		if ((D_tag[i][0] * 64) != m_y || (D_tag[i][1] * 64) != m_x) {
			data[aa] = D_tag[i][0] + D_tag[i][1];
			data2[aa] = i;
			data3[aa] = D_tag[i][2];
			aa++;
		}
		else
			base = D_tag[i][0] + D_tag[i][1];
	}

	for (int i = 0; i < aa; i++)
	{
		if (data3[i] == Wnamber)
		{
			data2[0] = data2[i];
			break;
		}
	}

	return data2[0];
}