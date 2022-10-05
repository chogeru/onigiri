#include "Goal.h"
Goal::Goal(const CVector2D& pos) :Base(eType_Goal) {

	m_img = COPY_RESOURCE("Goal", CImage);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(128, 224);

	//-(‰æ‘œ‚Ì•¡»)-
		//-(m_rect‚Ìİ’è - ‚È‚Ç
}

void Goal::Draw() {
	//-(‰æ‘œ‚Ì•`‰æ)-
	m_img.Draw();



}
