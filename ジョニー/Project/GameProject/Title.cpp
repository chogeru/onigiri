
#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	m_img = COPY_RESOURCE("title3", CImage);
	m_text = COPY_RESOURCE("titlerogo1ver2", CImage);
	m_pushz = COPY_RESOURCE("titlerogo2", CImage);
	m_str = COPY_RESOURCE("titlerogo3", CImage);
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

	m_text.Draw();
	m_text.SetPos(100, 110);

	m_pushz.Draw();
	m_pushz.SetPos(600, 210);

	m_str.Draw();
	m_str.SetPos(200, 410);

	//�����\��
	//m_title_text.Draw(64, 256, 0, 0, 0, "title");
	//m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}




