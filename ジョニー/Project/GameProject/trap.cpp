#include "trap.h"

trap::trap(const CVector2D& pos)
	:Base(eType_trap)
{
	m_img = COPY_RESOURCE("trap", CImage);
	m_pos = pos;
	//’†S‚ğİ’è
	m_img.SetCenter(16, 16);
	m_img.SetSize(64, 64);

}
void trap::Update()
{
	



}
void trap::Draw() {
	m_img.SetPos(m_pos);
	m_img.Draw();
}
void trap::Collision(Base* b)
{

}

