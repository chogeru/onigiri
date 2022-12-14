#include "Game.h"
//#include "Field.h"
//#include "Player.h"
#include "Enemy.h"
#include "Title.h"
#include"trap.h"
Game::Game() :Base(eType_Scene)
{
	//Base::Add(new Field());
	//Base::Add(new Player(CVector2D(0, 540), false));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 1, 540), true));
	//Base::Add(new Enemy(CVector2D(1280 + 256 * 2, 540), true));
	Base::Add(new Enemy(CVector2D(280 + 256 * 3, 440), true));
	Base::Add(new trap(CVector2D(222 + 256 * 3, 440), true));
	Base::Add(new trap(CVector2D(300 + 256 * 3, 440), true));


}
Game::~Game()
{
	//全てのオブジェクトを破棄
	Base::KillAll();
	//タイトルシーンへ
	Base::Add(new Title());
}

void Game::Update()
{
	//プレイヤー死亡　ボタン１でゲームシーン終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		SetKill();
	}
}
