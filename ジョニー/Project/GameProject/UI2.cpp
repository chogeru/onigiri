#include "GameData.h"
#include "UI2.h"
UI2::UI2() :Base(eType_UI) {
	m_img.Load("Image/UI2.png");
}
void UI2::Draw()
{
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}
	Base* trap = Base::FindObject(eType_trap);

	//“G‚ª‚¢‚È‚¯‚ê‚Î
	//if (enemy == nullptr) {
	//	//ƒQ[ƒ€ƒNƒŠƒA‚Ì•\Ž¦
	//	m_img.SetRect(0, 64, 0 + 160, 64 + 32);
	//	m_img.SetSize(160, 32);
	//	m_img.SetPos(100, 200);
	//	m_img.Draw();
	//}
	Base* player = Base::FindObject(eType_Player);

	//“G‚ª‚¢‚È‚¯‚ê‚Î
	if (player == nullptr) {
		//ƒQ[ƒ€ƒNƒŠƒA‚Ì•\Ž¦
		m_img.SetRect(0, 96, 160, 128);
		m_img.SetSize(160, 32);
		m_img.SetPos(200, 200);
		m_img.Draw();
	}

}