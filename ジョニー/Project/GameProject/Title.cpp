
#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//����ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	// �f�b�v������
	//m_img = COPY_RESOURCE("titlegamenn2gou", CImage);
	// ���A��
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//���A�ŉ���ver
	m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	//�}�X�R�b�g�ǂݍ���
	m_text = COPY_RESOURCE("Enemy2", CImage);
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

	m_ang += 0.1f;

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1285, 800);
	//�}�X�R�b�g�o��
	m_text.Draw();
	m_text.SetPos(900,500);
	m_text.SetSize(400, 700);
	m_text.SetAng(m_ang);
	m_text.SetCenter(200, 350);
		

}