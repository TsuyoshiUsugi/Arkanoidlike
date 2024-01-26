#include "in_game_block.h"
#include "player.h"
#include "scene_play.h"
#include "game_mamanger.h"

void in_game_block::draw()
{
    DrawRectGraph(pos_.x, pos_.y, 0, 0, size_.x, size_.y, ghl_, false);
    DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, GetColor(255, 255, 255), false);
}

void in_game_block::Hit(PlayerType player_type)
{
	ScenePlay* sc_play = dynamic_cast<ScenePlay*>(
		GameManager::GetInstance()->process_scene_);
	tnl::Vector3 dir = tnl::Vector3();
    sc_play->SpawnItemBlock(0, pos_, player_type);
}
