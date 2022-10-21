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
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Title());
	Base::Add(new Game());
	
}

void Gameover::Update()
{
	
	///�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		m_kill = true;





		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		Base::Add(new Title());

	}



}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	

}