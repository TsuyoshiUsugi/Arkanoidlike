#include "bounce_shoot.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"
#include "scene_play.h"
#include "game_mamanger.h"

void BounceShoot::shoot(tnl::Vector3 pos, PlayerType player_type)
{
	ScenePlay* sc_play = dynamic_cast<ScenePlay*>(
		GameManager::GetInstance()->process_scene_);

	// 弾の移動方向をプレイヤーの向いている方向にする
	if (player_type == PlayerType::Player1)
		move_dir_ = tnl::Vector3{1, -1, 1};
	else if (player_type == PlayerType::Player2)
		move_dir_ = tnl::Vector3{-1, 1, 1};

	// 弾を生成する
	sc_play->SpawnBullet(pos, move_dir_, true);
}
