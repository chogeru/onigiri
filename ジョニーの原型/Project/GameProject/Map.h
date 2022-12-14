#pragma once
//a//
#include "Base/Base.h"
//マップの横のチップ数
#define MAP_WIDTH		4000
//マップの縦のチップ数
#define MAP_HEIGHT		2200
//マップチップの大きさ
#define MAP_TIP_SIZE	 64

class Map : public Base {
private:
	CImage m_img;
	float m_ground_y;
public:
	Map();
	void Draw();
	void Update();
	//指定座標のチップ番号を取得
	int GetTip(const CVector2D& pos);
	//指定列、指定行のマップチップを取得
	int GetTip(int col, int raw);
	//マップとの当たり判定
	int CollisionMap(const CVector2D& pos);
	int CollisionMap(const CVector2D& pos, const CRect& rect);
	
	float GetGroundY() {
		return m_ground_y;
	}

};