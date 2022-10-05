#pragma once
#include "Base/Base.h"

class trap : public Base {
	CImage m_img;
	int m_cnt;

public:
	trap(const CVector2D& pos);
	void Update();
	void Draw();
	void Collision(Base* b);
};
