#pragma once
#include "Base/Base.h"
#include <GLLibrary.h>
#include"AnimData.h"
class Field : public Base {
private:
	//画像オブジェクト（前景）
	CImage m_foreground;
	//画像オブジェクト（遠景）
	CImage m_Map;
		//地面の高さ
		float m_ground_y;
public:
	/// コンストラクタ
	Field();
	/// 描画
	void Draw();

	/// 地面の高さを取得
	float GetGroundY() {
		return m_ground_y;
	}
};