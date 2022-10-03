#include "Enemy.h"





Enemy::Enemy(const CVector2D& p, bool flip) :
	Base(eType_Enemy) {
	//�摜����
	m_img = COPY_RESOURCE("Enemy", CImage);

	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//���]�t���O
	m_flip = flip;
}
void Enemy::Update() {

	

}

void Enemy::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(m_pos);
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
}
void Enemy::Collision(Base* b)
{

}
