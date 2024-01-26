#pragma once
#include "bullet.h"
#include "map_manager.h"
#include "player.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_base.h"

class ScenePlay : public SceneBase {
private:
	Player* player_1_;
	Player* player_2_;
	std::list<Bullet*> p1_bullet_list_;
	std::list<Bullet*> p2_bullet_list_;
	std::shared_ptr<map_manager> map_manager_;
public :
	ScenePlay();
	void CallResult(PlayerType winner);
	//void LoadMap();
	void SpawnItemBlock(int ghl, tnl::Vector3 pos, tnl::Vector3 dir);
	void SpawnBullet( tnl::Vector3& spawn_pos , tnl::Vector3& dir , bool isP1Shot);
	void UpdateBullet(float delta_time);
	void CheckHit();

	void update(float delta_time) override ;
	void drawBullet();
	void draw() override;
};

