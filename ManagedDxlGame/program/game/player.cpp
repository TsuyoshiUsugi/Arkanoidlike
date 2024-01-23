#include "game_mamanger.h"
#include "player.h"
#include "scene_play.h"
#include "normal_shoot.h"
#include "bounce_shoot.h"

Player::Player(PlayerType playerType) {
	playerType_ = playerType;
	width_ = 30;
	hight_ = 50;

	if (playerType_ == PlayerType::Player1)
		pos_ = left_player_start_vector3_pos_;
	else
	{
		pos_ = right_player_start_vector3_pos_;
		dir_ *= -1;	//���΂ɂ���
	}

	shoot_methods_.push_back(new NormalShoot());
	shoot_methods_.push_back(new BounceShoot());
}


//�e�̔��ˏ���
void Player::ShootBullet()
{
	tnl::Vector3 spawn_pos = pos_ + right_shoot_bullet_pos_;
	if (playerType_ == PlayerType::Player1)
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LSHIFT)) {
			for (size_t i = 0; i < shoot_methods_.size(); i++)
			{
				shoot_methods_[i]->shoot(spawn_pos, playerType_);
			}
		}
	}
	else
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RSHIFT)) {
			for (size_t i = 0; i < shoot_methods_.size(); i++)
			{
				shoot_methods_[i]->shoot(spawn_pos, playerType_);
			}
		}
	}
}

void Player::MoveHorizontal()
{
	if (playerType_ == PlayerType::Player1)
	{
		if (tnl::Input::IsKeyDown(eKeys::KB_W)) pos_.y -= 5.0f;
		if (tnl::Input::IsKeyDown(eKeys::KB_S)) pos_.y += 5.0f;
	}
	else
	{
		if (tnl::Input::IsKeyDown(eKeys::KB_UP)) pos_.y -= 5.0f;
		if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) pos_.y += 5.0f;
	}
}

// �v���C���A�b�v�f�[�g
void Player::update(float delta_time) {

	// ���E�L�[�ړ�
	MoveHorizontal();
	// �e�۔���
	ShootBullet();
}

// �v���C���`��
void Player::draw() {
	DrawBoxEx(pos_, width_, hight_, false);
}
