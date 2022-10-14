#include "trapbullet.h"
#include"trap.h"
#include"Base/Base.h"
#include"Map.h"
trapbullet::trapbullet(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
		m_img = COPY_RESOURCE("trapbullet", CImage);
	m_pos = pos;
	
	m_ang = ang;
	m_speed = speed;
//	trap = trapbullet;
}

void trapbullet::Update() {
	//m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed*5;
	//m_pos += m_vec;

}
void trapbullet::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void trapbullet::Collision(Base* b)
{
}
