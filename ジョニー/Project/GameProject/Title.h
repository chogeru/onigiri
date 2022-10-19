
#pragma once

#include "Base/Base.h"

class Title : public Base {
	//画像オブジェクト
	CImage m_img;
	CImage m_text;
	CImage m_text2;
	CImage m_text3;
	CImage m_text4;
	CImage m_text5;
	CImage m_text6;
	CImage m_text7;
	CImage m_text8;
	CImage m_text9;

	//文字表示オブジェクト
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};


