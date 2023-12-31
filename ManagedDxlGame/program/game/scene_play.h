#pragma once
#include "bullet.h"
#include "map_Loader.h"
#include "player.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_base.h"

class ScenePlay : public SceneBase {
private:
	Player* player_1_;
	Player* player_2_;
	std::list<Bullet*> p1_bullet_list_;
	std::list<Bullet*> p2_bullet_list_;
	map_Loader* map_loader_;

public :
	ScenePlay();
	void callResult(PlayerType winner);
	void LoadMap();

	void spawnBullet( tnl::Vector3& spawn_pos , tnl::Vector3& dir , bool isP1Shot);
	void updateBullet(float delta_time);
	void checkHit();

	void update(float delta_time) override ;
	void drawBullet();
	void draw() override;
};

