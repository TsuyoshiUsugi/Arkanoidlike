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
		dir_ *= -1;	//反対にする
	}

	shoot_methods_.push_back(new NormalShoot());
	//shoot_methods_.push_back(new BounceShoot());
}


//弾の発射処理
void Player::ShootBullet()
{
	if (playerType_ == PlayerType::Player1)
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LSHIFT)) {
			tnl::Vector3 spawn_pos = pos_ + right_shoot_bullet_pos_;
			for (size_t i = 0; i < shoot_methods_.size(); i++)
			{
				shoot_methods_[i]->shoot(spawn_pos, playerType_);
			}
		}
	}
	else
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RSHIFT)) {
			tnl::Vector3 spawn_pos = pos_ + left_shoot_bullet_pos_;
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

	if (pos_.y < 0 + hight_ / 2)
	{
		pos_.y = 0 + hight_ / 2;
	}
	else if (pos_.y > 780 - hight_ * 2)
	{
		pos_.y = 780 - hight_ * 2;
	}
}

// プレイヤアップデート
void Player::update(float delta_time) {
	// 左右キー移動
	MoveHorizontal();
	// 弾丸発射
	ShootBullet();
}

// プレイヤ描画
void Player::draw() {
	DrawBoxEx(pos_, width_, hight_, false);
}

/// <summary>
/// プレイヤーに弾の発射方法を追加する
/// </summary>
/// <param name="shoot_method"></param>
void Player::AddShootMethod(ShootMethodBase* shoot_method)
{
	shoot_methods_.push_back(shoot_method);
}
