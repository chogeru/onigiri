
#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	//m_img = COPY_RESOURCE("titlegamenn2gou", CImage);
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
}

Title::~Title()
{
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}
}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1285, 800);
	

	//�����\��
	//m_title_text.Draw(64, 256, 0, 0, 0, "title");
	//m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}




