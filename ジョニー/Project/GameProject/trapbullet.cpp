#include "trapbullet.h"
trapbullet::trapbullet(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	m_img = COPY_RESOURCE("trapbullet", CImage);
	

	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_img.SetCenter(32, 16);
	m_img.SetCenter(64, 16);
	m_ang = ang;
	m_speed = speed;
}

void trapbullet::Update() {
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;
	if (PUSH(CInput::eMouseL)) {
		Base::Add(new trapbullet(eType_trapbullet, m_pos, m_ang, 4));
	}
}
void trapbullet::Draw() {
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void trapbullet::Collision(Base* b)
{
}
