#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {

	m_img = COPY_RESOURCE("Goal", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(128, 224);

	//-(�摜�̕���)-
		//-(m_rect�̐ݒ� - �Ȃ�
}

void Goal::Draw() {
	//-(�摜�̕`��)-
	m_img.Draw();



}
