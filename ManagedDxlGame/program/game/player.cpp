#include "game_mamanger.h"
#include "player.h"
#include "scene_play.h"

//弾の発射処理
void Player::ShootBullet()
{
	if (playerType_ == PlayerType::Player1)
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_LSHIFT)) {
			tnl::Vector3 spawn_pos = pos_ + right_shoot_bullet_pos_;
			ScenePlay* sc_play = dynamic_cast<ScenePlay*>( 
				GameManager::GetInstance()->process_scene_ ) ;
			const tnl::Vector3 dir = {1 ,0 , 0};
			sc_play->spawnBullet( spawn_pos , dir_, true);
		}
	}
	else
	{
		if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RSHIFT)) {
			tnl::Vector3 spawn_pos = pos_ + left_shoot_bullet_pos_;
			ScenePlay* sc_play = dynamic_cast<ScenePlay*>( 
				GameManager::GetInstance()->process_scene_ ) ;
		
			sc_play->spawnBullet( spawn_pos, dir_, false);
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
