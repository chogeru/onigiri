#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {

	m_img = COPY_RESOURCE("Goal", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(128, 224);

	//-(ζΜ‘»)-
		//-(m_rectΜέθ - ΘΗ
}

void Goal::Draw() {
	//-(ζΜ`ζ)-
	m_img.Draw();



}
