#include "../dxlib_ext/dxlib_ext.h"
#include "scene_play.h"
#include "player.h"
#include "bullet.h"
#include "game_mamanger.h"
#include "scene_result.h"

ScenePlay::ScenePlay() {
	auto player1 = new Player(PlayerType::Player1);
	player_1_ = player1;
	objects_.emplace_back( player_1_ );

	auto player2 = new Player(PlayerType::Player2);
	player_2_ = player2;
	objects_.emplace_back( player_2_ );
}

void ScenePlay::callResult(PlayerType winner)
{
	GameManager* mgr = GameManager::GetInstance();
	mgr->setWinner(winner);
	mgr->changeScene( new scene_result () );
}

//各プレイヤーと弾の当たり判定を行う
void ScenePlay::checkHit() {
	// オブジェクトのアップデート処理
	auto it = p1_bullet_list_.begin();
	while (it != p1_bullet_list_.end()) {
		auto pos = (*it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(pos.x, pos.y, player_2_->pos_.x, player_2_->pos_.y, 5, 5))
		{
			//当たり判定を行う
			DrawStringEx(10, 20, -1, "HitP1");
			callResult(PlayerType::Player1);
			break;
		}
		it++;
	}

	it = p2_bullet_list_.begin();
	while (it != p2_bullet_list_.end()) {
		auto pos = (*it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(pos.x, pos.y, player_1_->pos_.x, player_1_->pos_.y, 5, 5)) {	//当たり判定を行う
			DrawStringEx(10, 30, -1, "HitP2");
			callResult(PlayerType::Player2);
			break;
		}
		it++;
	}
}

//弾丸を生成する
void ScenePlay::spawnBullet( tnl::Vector3& spawn_pos, tnl::Vector3& dir, bool isP1Shot) {
	auto bullet = new Bullet( spawn_pos, dir);
	objects_.emplace_back( bullet );
	if (isP1Shot)
	{
		p1_bullet_list_.emplace_back( bullet );
	}
	else
	{
		p2_bullet_list_.emplace_back( bullet );
	}
}

void ScenePlay::update(float delta_time) {
	SceneBase::update(delta_time);
	checkHit();
}

void ScenePlay::draw() {
	SceneBase::draw();

	DrawStringEx(10, 10, -1, "scene play");
}

