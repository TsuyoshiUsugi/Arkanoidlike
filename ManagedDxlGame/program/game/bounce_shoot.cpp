#include "bounce_shoot.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"
#include "scene_play.h"
#include "game_mamanger.h"

BounceShoot::BounceShoot(tnl::Vector3 dir)
{
	move_dir_ = dir;
}

void BounceShoot::Shoot(tnl::Vector3 pos, PlayerType player_type)
{
	std::shared_ptr<ScenePlay> sc_play = std::dynamic_pointer_cast<ScenePlay>(
		GameManager::GetInstance()->process_scene_);

	// ’e‚ÌˆÚ“®•ûŒü‚ðƒvƒŒƒCƒ„[‚ÌŒü‚¢‚Ä‚¢‚é•ûŒü‚É‚·‚é
	if (player_type == PlayerType::Player1)
	{
		sc_play->SpawnBullet(pos, move_dir_, true);
	}
	else if (player_type == PlayerType::Player2)
	{
		sc_play->SpawnBullet(pos, move_dir_, false);
	}
}
