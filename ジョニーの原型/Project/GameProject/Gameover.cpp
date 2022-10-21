#include "Gameover.h"
#include "Game.h"
#include "Title.h"
Gameover::Gameover():Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("gameovergamenn", CImage);
	
}

Gameover::~Gameover()
{
	//タイトル破棄時にゲームシーンへ移行
	Base::Add(new Title());
	Base::Add(new Game());
	
}

void Gameover::Update()
{
	
	///ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		m_kill = true;





		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーンへ
		Base::Add(new Title());

	}



}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	

}