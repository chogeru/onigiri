#include "END.h"
#include "Game.h"

END::END() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("END", CImage);
}



END::~END()
{
	//�S�ẴI�u�W�F�N�g��j��
	Base::KillAll();
	//�Q�[���V�[����
	Base::Add(new Game());
}
void END::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		SetKill();
	}
}

void END::Draw()
{
	m_img.Draw();
	//�����\��
	m_title_text.Draw(64, 256, 0, 0, 0, "Title");
	m_title_text.Draw(64, 512, 0, 0, 0, "Push Z");
}
