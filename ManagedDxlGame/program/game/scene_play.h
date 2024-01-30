#pragma once
#include "bullet.h"
#include "map_manager.h"
#include "player.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_base.h"
#include <time.h>
#include <string>
#include <numbers>

class ScenePlay : public SceneBase {
private:
	std::shared_ptr<Player> player_1_;
	std::shared_ptr<Player> player_2_;
	std::list<std::shared_ptr<Bullet>> p1_bullet_list_;
	std::list<std::shared_ptr<Bullet>> p2_bullet_list_;
	std::shared_ptr<map_manager> map_manager_;
	PlayerType winner_ = PlayerType::None;
	tnl::Sequence<ScenePlay> on_clear_sequence_ = tnl::Sequence<ScenePlay>(this, &ScenePlay::ExplodeSequence);
	bool has_exploded_ = false;
public :
	ScenePlay();
	bool ExplodeSequence(float delta_time);
	//void LoadMap();
	void SpawnItemBlock(int ghl, tnl::Vector3 pos, PlayerType player_type);
	void SpawnBullet( tnl::Vector3& spawn_pos , tnl::Vector3& dir , bool isP1Shot);
	void UpdateBullet(float delta_time);
	void CheckHit();

	void Update(float delta_time) override ;
	void DrawBullet();
	void Draw() override;
	void DrawHelp();
};

