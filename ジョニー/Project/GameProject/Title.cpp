#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//����ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	// �f�b�v������
	m_img = COPY_RESOURCE("titlegamenn2gou", CImage);
	// ���A��
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//���A�ŉ���ver
	//m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	//�}�X�R�b�g�ǂݍ���
	m_text = COPY_RESOURCE("Enemy", CImage);
	m_text2 = COPY_RESOURCE("Enemy2", CImage);
	m_text3 = COPY_RESOURCE("Enemy3", CImage);
}

Title::~Title()
{
	//�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	int game_state = 0;
	switch (game_state) {
	case 0:
		//�|�[�Y���̍X�V����
		if (PUSH(CInput::eButton10))
			game_state = 1;
		break;
	case 1:
		//�Q�[�����̍X�V����
		break;
	}




	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
	


}

void Title::Update()
{
	//�{�^���P�Ń^�C�g���j��
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}

	m_ang += 0.2f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	//�}�X�R�b�g�o��
	m_text.Draw();
	//���W�ݒ�
	m_text.SetPos(1800,500);
	//�傫���ݒ�
	m_text.SetSize(400, 700);
	//��]
	m_text.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text.SetCenter(200, 350);
	//�}�X�R�b�g�o��
	m_text2.Draw();
	//���W�ݒ�
	m_text2.SetPos(1800, 700);
	//�傫���ݒ�
	m_text2.SetSize(400, 700);
	//��]
	m_text2.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text2.SetCenter(200, 350);
	//�}�X�R�b�g�o��
	m_text3.Draw();
	//���W�ݒ�
	m_text3.SetPos(1800, 900);
	//�傫���ݒ�
	m_text3.SetSize(400, 700);
	//��]
	m_text3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text3.SetCenter(200, 350);
}