
#pragma once

#include "Base/Base.h"

class Title : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	CImage m_text;
	CImage m_pushz;
	CImage m_str;
	//�����\���I�u�W�F�N�g
	CFont m_title_text;
public:
	Title();
	~Title();
	void Update();
	void Draw();
};


