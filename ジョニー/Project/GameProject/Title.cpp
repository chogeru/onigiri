
#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//初期ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	// デップ抹消版
	m_img = COPY_RESOURCE("titlegamenn2gou", CImage);
	// 洞窟版
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//洞窟版改良ver
	//m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	//マスコット読み込み
	m_text = COPY_RESOURCE("Enemy2", CImage);
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

	m_ang += 0.2f;

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	//マスコット出力
	m_text.Draw();
	//座標設定
	m_text.SetPos(1800,500);
	//大きさ設定
	m_text.SetSize(400, 700);
	//回転
	m_text.SetAng(m_ang);
	//中心位置設定
	m_text.SetCenter(200, 350);
		

}