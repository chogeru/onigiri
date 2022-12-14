#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//初期ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	
	// 洞窟版
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//洞窟版改良ver
	//m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	// デップ抹消版
	m_img = COPY_RESOURCE("titlegamenn2gou", CImage); 
	//タイプZ
	//m_img = COPY_RESOURCE("titletypez", CImage);
	//m_img2 = COPY_RESOURCE("titlerogo2", CImage);
	
	//マスコット読み込み
	/*m_text = COPY_RESOURCE("Enemy", CImage);
	m_text2 = COPY_RESOURCE("Enemy2", CImage);
	m_text3 = COPY_RESOURCE("Enemy3", CImage);
	m_text4 = COPY_RESOURCE("Enemy4", CImage);
	m_text5 = COPY_RESOURCE("Enemy5", CImage);
	m_text6 = COPY_RESOURCE("Enemy6", CImage);
	m_text7 = COPY_RESOURCE("Enemy7", CImage);*/
}

Title::~Title()
{
	//全てのオブジェクトを破棄
	//Base::KillAll();
	




	//タイトル破棄時にゲームシーンへ移行
	Base::Add(new Game());
	


}

void Title::Update()
{
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}

	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
/*
	m_img2.Draw();
	m_text.SetSize(100, 300);
	m_img2.SetPos(1000, 300);
	m_img2.SetAng(m_ang);
	m_text.SetCenter(50, 150);

	//マスコット出力
	m_text.Draw();
	//座標設定
	m_text.SetPos(1800,900);
	//大きさ設定
	m_text.SetSize(400, 700);
	//回転
	m_text.SetAng(m_ang);
	//中心位置設定
	m_text.SetCenter(200, 350);


	//マスコット出力
	m_text.Draw();
	//座標設定
	m_text.SetPos(1800, 200);
	//大きさ設定
	m_text.SetSize(400, 700);
	//回転
	m_text.SetAng(m_ang);
	//中心位置設定
	m_text.SetCenter(200, 350);

	
	//マスコット出力
	m_text2.Draw();
	//座標設定
	m_text2.SetPos(300, 900);
	//大きさ設定
	m_text2.SetSize(400, 700);
	//回転
	m_text2.SetAng(m_ang);
	//中心位置設定
	m_text2.SetCenter(200, 350);


	//マスコット出力
	m_text3.Draw();
	//座標設定
	m_text3.SetPos(200, 200);
	//大きさ設定
	m_text3.SetSize(400, 700);
	//回転
	m_text3.SetAng(m_ang);
	//中心位置設定
	m_text3.SetCenter(200, 350);

	//マスコット出力
	m_text4.Draw();
	//座標設定
	m_text4.SetPos(500, 500);
	//大きさ設定
	m_text4.SetSize(400, 700);
	//回転
	m_text4.SetAng(m_ang);
	//中心位置設定
	m_text4.SetCenter(200, 350);

	
	//マスコット出力
	m_text5.Draw();
	//座標設定
	m_text5.SetPos(1800, 500);
	//大きさ設定
	m_text5.SetSize(400, 700);
	//回転
	m_text5.SetAng(m_ang);
	//中心位置設定
	m_text5.SetCenter(200, 350);
	


	
	//マスコット出力
	m_text6.Draw();
	//座標設定
	m_text6.SetPos(900, 900);
	//大きさ設定
	m_text6.SetSize(400, 700);
	//回転
	m_text6.SetAng(m_ang);
	//中心位置設定
	m_text6.SetCenter(200, 350);
	

	
	//マスコット出力
	m_text7.Draw();
	//座標設定
	m_text7.SetPos(900, 400);
	//大きさ設定
	m_text7.SetSize(400, 700);
	//回転
	m_text7.SetAng(m_ang);
	//中心位置設定
	m_text7.SetCenter(200, 350);
	*/


}