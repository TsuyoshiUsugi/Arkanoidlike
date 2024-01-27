#include "bounce_shoot.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"
#include "scene_play.h"
#include "game_mamanger.h"

BounceShoot::BounceShoot(tnl::Vector3 dir)
{

}

void BounceShoot::shoot(tnl::Vector3 pos, PlayerType player_type)
{
	ScenePlay* sc_play = dynamic_cast<ScenePlay*>(
		GameManager::GetInstance()->process_scene_);

	// ’e‚ÌˆÚ“®•ûŒü‚ðƒvƒŒƒCƒ„[‚ÌŒü‚¢‚Ä‚¢‚é•ûŒü‚É‚·‚é
	if (player_type == PlayerType::Player1)
		move_dir_ = tnl::Vector3{1, -1, 1};
	else if (player_type == PlayerType::Player2)
		move_dir_ = tnl::Vector3{-1, 1, 1};

	// ’e‚ð¶¬‚·‚é
	sc_play->SpawnBullet(pos, move_dir_, true);
}
