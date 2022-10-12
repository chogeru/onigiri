
#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//初期ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	// デップ抹消版
	//m_img = COPY_RESOURCE("titlegamenn2gou", CImage);
	// 洞窟版
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//洞窟版改良ver
	m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	//マスコット読み込み
	m_text = COPY_RESOURCE("Enemy", CImage);
}

Title::~Title()
{
	//タイトル破棄時にゲームシーンへ移行
	Base::Add(new Game());
}

void Title::Update()
{
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1285, 800);
	//マスコット出力
	m_text.Draw();
	m_text.SetPos(900,100);
	m_text.SetSize(400, 700);

	//文字表示
	//m_title_text.Draw(64, 256, 0, 0, 0, "title");
	//m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}