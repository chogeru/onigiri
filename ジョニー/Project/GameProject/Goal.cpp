#include "Goal.h"
#include"Game.h"
#include "Title.h"
Goal::Goal(const CVector2D& pos)
	:Base(eType_Goal) {

	m_img = COPY_RESOURCE("Goal", CImage);
	m_pos = pos;
	m_rect = CRect(-64, -64, 64, 64);
	//
}
/*
void Goal::Update()
{

	Base::Add(new Title());

}
*/




void Goal::Draw()
{
	m_img.SetSize(64, 64);
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	
}