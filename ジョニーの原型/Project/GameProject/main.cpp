//ゲーム係機能のインクルード
#include <GLLibrary.h>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#include"Field.h"
#include"Base/Base.h"
#include "Player.h"
#include"Enemy.h"
//#include"Field.h"
#include"Game.h"
#include"Goal.h"
#include"Map.h"
#include"Title.h"
#include"AnimData.h"
#include"trapbullet.h"
#include"trap.h"
#include"UI.h"
#include"Wall.h"
#include "Gameover.h"
#include"M.h"
#include"END.h"
//なにみてんだや//
//--------------------------------------------
//グローバル変数領域
//--------------------------------------------
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
//(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)<なにみてんだや
void MainLoop(void) {
	//--------------------------------------------------------------
	//ゲーム中の動きはここに書く
	//ゲーム中はこの関数_を1秒間に60回呼び出している
	//--------------------------------------------------------------
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();
	

}
void Init(void)
{

	CFPS::SetFPS(60);
	//フレーム制御初期化
	CFPS::Init();
	//ボタンの設定
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//初期化の命令を書く
	//ゲーム起動時に一度だけ呼ばれる
	//-----------------------------------------------------
	ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
;   ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png", player_anim_data, 32, 32));
	//ADD_RESOURCE("Map", CImage::CreateImage("Image/Map.png"));
	ADD_RESOURCE("ForeGround", CImage::CreateImage("Image/ForeGround.png"));
	ADD_RESOURCE("titlegamenn", CImage::CreateImage("Image/titlegamenn.png"));
	ADD_RESOURCE("titlegamenn2gou", CImage::CreateImage("Image/titlegamenn2gou.png"));
	ADD_RESOURCE("titlegamenntype2", CImage::CreateImage("Image/titlegamenntype2.png"));
	ADD_RESOURCE("titlegamenntype2ver2", CImage::CreateImage("Image/titlegamenntype2ver2.png"));
	ADD_RESOURCE("Enemy2", CImage::CreateImage("Image/Enemy2.png"));
	ADD_RESOURCE("Enemy3", CImage::CreateImage("Image/Enemy3.png"));
	ADD_RESOURCE("Enemy4", CImage::CreateImage("Image/Enemy4.png"));
	ADD_RESOURCE("Enemy5", CImage::CreateImage("Image/Enemy5.png"));
	ADD_RESOURCE("Enemy6", CImage::CreateImage("Image/Enemy6.png"));
	ADD_RESOURCE("Enemy7", CImage::CreateImage("Image/Enemy7.png"));
	ADD_RESOURCE("gameovergamenn", CImage::CreateImage("Image/gameovergamenn.png"));
	ADD_RESOURCE("M", CImage::CreateImage("Image/M.png"));
	//-----------------------------------------------------
//初期化の命令を書く
//ゲーム起動時に一度だけ呼ばれる
//-----------------------------------------------------
//画像の読み込みと登録　”リソース名”　　　　”ファイル名” , アニメーションデータ , 幅 , 高さ
	//ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png", player_anim_data, 256, 256));
	ADD_RESOURCE("Enemy", CImage::CreateImage("Image/Enemy.png"));
	//ADD_RESOURCE("a", CImage::CreateImage("Image/a.png"));
	//プレイヤーの生成
	//Base::Add(new Player(CVector2D(200, 500), false));
	ADD_RESOURCE("trap", CImage::CreateImage("Image/trap.png"));
	ADD_RESOURCE("trapbullet", CImage::CreateImage("Image/trapbullet.png"));
	ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
	ADD_RESOURCE("Wall", CImage::CreateImage("Image/Wall.png"));

	ADD_RESOURCE("titletypez", CImage::CreateImage("Image/titletypez.png"));
	ADD_RESOURCE("titlerogo2", CImage::CreateImage("Image/titlerogo2.png"));


	ADD_RESOURCE("END", CImage::CreateImage("Image/END.png"));
	ADD_RESOURCE("Goal", CImage::CreateImage("Image/Goal.png"));
	//敵のの生成//
	//Base::Add(new Enemy(CVector2D(800, 500), true));
	//Enemy(CVector2D(200, 500));
	/*Base::Add(new trap(CVector2D(500, 200), false));
	Base::Add(new trap(CVector2D(100, 200), false));
	Base::Add(new trap(CVector2D(300, 200), false));
	Base::Add(new trap(CVector2D(200, 200), false))*/
	Base::Add(new Map());
	Base::Add(new Title);
	Base::Add(new Player(CVector2D(400, 400), false));
	Base::Add(new UI());
	//Base::Add(new Goal(CVector2D(300, 1100)));
	Base::Add(new Wall());



	SOUND("jump")->Load("sound/BGM/jumpman.wav");
	SOUND("field")->Load("sound/BGM/bgm_com.wav");
	//BGM　ループ再生
	SOUND("field")->Play();
	





}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//画面解像度変動
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//画面解像度固定
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//フルスクリーン?ウインドウモードの切り替え
//Alt+Enterで切り替える
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// メモリリーク検出
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//ブレンドの有効化
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//固定シェーダー用
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//各バッファーをクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}
