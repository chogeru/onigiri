#pragma once

#include "Base/Base.h"

class END : public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
public:
	END();
	~END();
	void Update();
	void Draw();
};

