#include "normal_shoot.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_play.h"
#include "player.h"
#include "game_mamanger.h"

void NormalShoot::shoot(tnl::Vector3 spawn_pos, PlayerType player_type)
{
	//’Êí‚Ì’e‚ğ”­Ë‚·‚éˆ—
	ScenePlay* sc_play = dynamic_cast<ScenePlay*>(
		GameManager::GetInstance()->process_scene_);
	tnl::Vector3 dir = { 1 ,0 , 0 };

	if (player_type == PlayerType::Player1)
	{
		sc_play->spawn_bullet(spawn_pos, dir, true);
	}
	else
	{
		sc_play->spawn_bullet(spawn_pos, dir *= -1, false);
	}
}
