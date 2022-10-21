#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	//����ver
	//m_img = COPY_RESOURCE("titlegamenn", CImage);
	
	// ���A��
	//m_img = COPY_RESOURCE("titlegamenntype2", CImage);
	//���A�ŉ���ver
	//m_img = COPY_RESOURCE("titlegamenntype2ver2", CImage);
	// �f�b�v������
	//m_img = COPY_RESOURCE("titlegamenn2gou", CImage); 
	//�^�C�vZ
	m_img = COPY_RESOURCE("titletypez", CImage);
	m_img2 = COPY_RESOURCE("titlerogo2", CImage);
	
	//�}�X�R�b�g�ǂݍ���
	m_text = COPY_RESOURCE("Enemy", CImage);
	m_text2 = COPY_RESOURCE("Enemy2", CImage);
	m_text3 = COPY_RESOURCE("Enemy3", CImage);
	m_text4 = COPY_RESOURCE("Enemy4", CImage);
	m_text5 = COPY_RESOURCE("Enemy5", CImage);
	m_text6 = COPY_RESOURCE("Enemy6", CImage);
	m_text7 = COPY_RESOURCE("Enemy7", CImage);
}

Title::~Title()
{
	//�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	




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

	m_img2.Draw();
	m_text.SetSize(100, 300);
	m_img2.SetPos(1000, 300);
	m_img2.SetAng(m_ang);
	m_text.SetCenter(50, 150);

	//�}�X�R�b�g�o��
	m_text.Draw();
	//���W�ݒ�
	m_text.SetPos(1800,900);
	//�傫���ݒ�
	m_text.SetSize(400, 700);
	//��]
	m_text.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text.SetCenter(200, 350);


	//�}�X�R�b�g�o��
	m_text.Draw();
	//���W�ݒ�
	m_text.SetPos(1800, 200);
	//�傫���ݒ�
	m_text.SetSize(400, 700);
	//��]
	m_text.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text.SetCenter(200, 350);

	
	//�}�X�R�b�g�o��
	m_text2.Draw();
	//���W�ݒ�
	m_text2.SetPos(300, 900);
	//�傫���ݒ�
	m_text2.SetSize(400, 700);
	//��]
	m_text2.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text2.SetCenter(200, 350);


	//�}�X�R�b�g�o��
	m_text3.Draw();
	//���W�ݒ�
	m_text3.SetPos(200, 200);
	//�傫���ݒ�
	m_text3.SetSize(400, 700);
	//��]
	m_text3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text3.SetCenter(200, 350);

	//�}�X�R�b�g�o��
	m_text4.Draw();
	//���W�ݒ�
	m_text4.SetPos(500, 500);
	//�傫���ݒ�
	m_text4.SetSize(400, 700);
	//��]
	m_text4.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text4.SetCenter(200, 350);

	
	//�}�X�R�b�g�o��
	m_text5.Draw();
	//���W�ݒ�
	m_text5.SetPos(1800, 500);
	//�傫���ݒ�
	m_text5.SetSize(400, 700);
	//��]
	m_text5.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text5.SetCenter(200, 350);
	


	
	//�}�X�R�b�g�o��
	m_text6.Draw();
	//���W�ݒ�
	m_text6.SetPos(900, 900);
	//�傫���ݒ�
	m_text6.SetSize(400, 700);
	//��]
	m_text6.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text6.SetCenter(200, 350);
	

	
	//�}�X�R�b�g�o��
	m_text7.Draw();
	//���W�ݒ�
	m_text7.SetPos(900, 200);
	//�傫���ݒ�
	m_text7.SetSize(400, 700);
	//��]
	m_text7.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_text7.SetCenter(200, 350);
	


}