#include "Map.h"
#include"Base/Base.h"
#include"Player.h"
#include"trap.h"
#include"Enemy.h"
#include"trapbullet.h"
#include"Wall.h"
#include"M.h"
#include"Goal.h"
static int stage1data[MAP_HEIGHT][MAP_WIDTH] = {
	//aa////
	
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,0,3,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4},
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
	{ 1,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,6,0,6,6,6,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,6,0,0,0,0,0,0,0,1,1,3,0,0,0,1,3,0,0,1,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,6,6,1,3,6,6,6,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,0,3,0,0,3,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,4,1},
	{ 1,4,0,6,6,6,6,6,6,6,2,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,6,1,3,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,3,1,1,1,1,1,1,3,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

	};


Map::Map() : Base(eType_Field)
{



	m_ground_y = 500;


	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (stage1data[i][j] == 0)continue;
			int& t = stage1data[i][j];
			if (t == 3)
			{
				int x;
				int y;
				x = j * MAP_TIP_SIZE;
				y = i * MAP_TIP_SIZE;
				//xとyの位置に敵を生成する
				//i行j列のチップのデータを０に戻す

				Base::Add(new trap(CVector2D(x, y), true));
				//Base::Add(new trapbullet(CVector2D(), true));
				t = 0;


			}



		}
	}
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (stage1data[i][j] == 0)continue;
			int& t = stage1data[i][j];
			if (t == 4)
			{
				int x;
				int y;
				x = j * MAP_TIP_SIZE;
				y = i * MAP_TIP_SIZE;
				//xとyの位置に敵を生成する
				//i行j列のチップのデータを０に戻す

				//Base::Add(new Goal(CVector2D(x, y), true));
				Base::Add(new Goal(CVector2D(x, y)));
				//Base::Add(new trapbullet(CVector2D(), true));
				t = 0;


			}



		}
	}
	for (int i = 0; i < MAP_HEIGHT; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (stage1data[i][j] == 0)continue;
			int& t = stage1data[i][j];
			if (t == 6)
			{
				int x;
				int y;
				x = j * MAP_TIP_SIZE;
				y = i * MAP_TIP_SIZE;
				//xとyの位置に敵を生成する
				//i行j列のチップのデータを０に戻す

				Base::Add(new Player(CVector2D(x, y), true));
				//Base::Add(new Player(CVector2D(x, y)));
				//Base::Add(new trapbullet(CVector2D(), true));
				t = 0;


			}



		}
	}
		for (int i = 0; i < MAP_HEIGHT; i++) {
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (stage1data[i][j] == 0)continue;
				int& t = stage1data[i][j];
				if (t == 2)
				{
					int x;
					int y;
					x = j * MAP_TIP_SIZE;
					y = i * MAP_TIP_SIZE;
					//xとyの位置に敵を生成する
					//i行j列のチップのデータを０に戻す

					Base::Add(new Enemy(CVector2D(x, y), true));
					//Base::Add(new trapbullet(CVector2D(), true));
					t = 0;


				}
				//画像複製
				m_img = COPY_RESOURCE("MapTip", CImage);
			}
		}
	
}

	void Map::Draw()
	{
		/*float sc;
		sc = m_scroll.x / 4;
		//m_ing.SetRect(sc, 0, sc + 1280, 720);
		sc = m_scroll.x;
		//m_ing.SetRect(sc, 0, sc + 1280, 720);
		*/
		//マップチップによる表示の繰り返し
		for (int i = 0; i < MAP_HEIGHT; i++) 
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if (stage1data[i][j] == 0)continue;
				int t = stage1data[i][j];
				//画像切り抜き
				m_img.SetRect(32, 0, 32 + 32, 32);
				//表示サイズ設定
				m_img.SetSize(MAP_TIP_SIZE, MAP_TIP_SIZE);
				//表示位置設定
				m_img.SetPos(MAP_TIP_SIZE * j - m_scroll.x, MAP_TIP_SIZE * i - m_scroll.y);

				//描画
				m_img.Draw();
			}
		}
}
void Map::Update()
{
	m_scroll.x = m_pos.x - 1280 / 2;

}
;int Map::GetTip(const CVector2D& pos)
{
	//列を計算
	int col = pos.x / MAP_TIP_SIZE;
	//列の制限(0〜MAP_WIDTH-1)
	if (col < 0) col = 0;
	if (col > MAP_WIDTH - 1) col = MAP_WIDTH - 1;
	//行を計算
	int raw = pos.y / MAP_TIP_SIZE;
	//行の制限(0〜MAP_HEIGHT-1)
	if (raw < 0) raw = 0;
	if (raw > MAP_HEIGHT - 1) raw = MAP_HEIGHT - 1;
	//チップデータを返却
	return GetTip(col, raw);
}
int Map::GetTip(int col, int raw)
{
	return stage1data[raw][col];
}

int Map::CollisionMap(const CVector2D& pos)
{
	//1点のみ検証
	int t = GetTip(pos);
	if (t != 0) return t;

	return 0;
}
int Map::CollisionMap(const CVector2D& pos, const CRect& rect)
{
	//左上
	int t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_top));
	if (t != 0) return t;
	//右上
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_top));
	if (t != 0) return t;
	//左下
	t = GetTip(CVector2D(pos.x + rect.m_left, pos.y + rect.m_bottom));
	if (t != 0) return t;
	//右下
	t = GetTip(CVector2D(pos.x + rect.m_right, pos.y + rect.m_bottom));
	if (t != 0) return t;
	return 0;
}
