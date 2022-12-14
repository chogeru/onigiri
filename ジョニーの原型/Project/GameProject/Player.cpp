#include "Player.h"
#include "AnimData.h"
//#include"Field.h"
#include "Map.h"
#include"Effect.h"
//#include"Goal.h"
//#include"Slash.h"
#include"Title.h"
#include"END.h"

Player::Player(const CVector2D& pos, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//m_img = COPY_RESOURCE("END", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = pos;
	
		//スクロール設定
		m_scroll.x = m_pos.x - 1280 / 2;
	


	//中心位置設定
	m_img.SetCenter(32, 32);
	m_img.SetSize(64, 64);
	m_rect = CRect(-32, -32, 32, 32);
	//反転フラグ
	m_flip = flip;
	m_state = eState_Idle;
	m_is_ground = true;
	m_rad = 32;
	m_damage_no = -1;
	m_hp = 500;

}
void Player::Update() {
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;



	//アニメーション更新
	m_img.UpdateAnimation();
	//スクロール設定
	m_scroll.x = m_pos.x - 1280 / 2;
	m_scroll.y = m_pos.y - 600;


}

void Player::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));;
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();

}
void Player::Collision(Base* b)
{

	switch (b->m_type) {
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			
			//if (PUSH(CInput::eButton1)){
			b->SetKill();
			
			Base::Add(new END());
			//}
		}
		break;
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) {
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				m_vec.y = 0;
				m_is_ground = true;
			}
			if (m_pos.y > m->GetGroundY()) {
				
				SetKill();
				
			}
		}
		
		

		break;
	}
	/*case eType_trap_Attack:
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();
				m_hp -= 100;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}break;
	/*case eType_Enemy_Attack:
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				m_damage_no = s->GetAttackNo();
				m_hp -= 100;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood",m_pos + CVector2D(0, -128), m_flip));
			}
		}break;*/


}



void Player::StateIdle()
{
	const float move_speed = 6;
	//ジャンプ力
	const float jump_pow = 12;


	bool move_flag = false;
	if (HOLD(CInput::eLeft)) {
		m_pos.x += -move_speed;
		m_flip = true;
		move_flag = true;
	}
	if (HOLD(CInput::eRight)) {
		m_pos.x += move_speed;
		m_flip = false;
		move_flag = true;
	}
	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		
		m_is_ground = false;
		
		
	}


	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else if(m_vec.y<0)
		SOUND("jump")->Load("sound/BGM/jumpman.wav",false);

		else
			//下降アニメーション
			m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//移動中なら
	else
	{

		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
}

void Player::StateAttack()
{
}

void Player::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Player::StateDown()
{

	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));

		m_kill = true;
	}
}