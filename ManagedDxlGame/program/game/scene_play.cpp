#include "../dxlib_ext/dxlib_ext.h"
#include "scene_play.h"
#include "player.h"
#include "bullet.h"
#include "game_mamanger.h"
#include "scene_result.h"

ScenePlay::ScenePlay() {
	player_1_ = new Player(PlayerType::Player1);
	objects_.emplace_back( player_1_ );
	player_2_ = new Player(PlayerType::Player2);
	objects_.emplace_back( player_2_ );

	map_manager_ = new map_manager();
	map_manager_->load_map();
}

void ScenePlay::callResult(PlayerType winner)
{
	GameManager* mgr = GameManager::GetInstance();
	mgr->setWinner(winner);
	mgr->changeScene( new scene_result () );
}

//各プレイヤーと弾の当たり判定を行う
void ScenePlay::check_hit() {
	// オブジェクトのアップデート処理
	auto it = p1_bullet_list_.begin();
	PlayerType winner = PlayerType::None;

	while (it != p1_bullet_list_.end() && winner == PlayerType::None) {
		auto pos = (*it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(pos.x, pos.y, player_2_->pos_.x, player_2_->pos_.y, player_2_->width_, player_2_->hight_))
		{
			//当たり判定を行う
			DrawStringEx(10, 20, -1, "HitP1");
			winner = PlayerType::Player1;
			break;
		}
		it++;
	}

	it = p2_bullet_list_.begin();

	while (it != p2_bullet_list_.end() && winner == PlayerType::None) {
		auto pos = (*it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(pos.x, pos.y, player_1_->pos_.x, player_1_->pos_.y, player_1_->width_, player_1_->hight_)) {	//当たり判定を行う
			DrawStringEx(10, 30, -1, "HitP2");
			winner = PlayerType::Player2;
			break;
		}
		it++;
	}

	if (winner != PlayerType::None) callResult(winner);
}

//弾丸を生成する
void ScenePlay::spawn_bullet( tnl::Vector3& spawn_pos, tnl::Vector3& dir, bool isP1Shot) {
	auto bullet = new Bullet( spawn_pos, dir);
	if (isP1Shot)
	{
		p1_bullet_list_.emplace_back( bullet );
	}
	else
	{
		p2_bullet_list_.emplace_back( bullet );
	}
}

void ScenePlay::updateBullet(float delta_time)
{
	auto it = p1_bullet_list_.begin();
	while (it != p1_bullet_list_.end()) {
		(*it)->update(delta_time);
		if (!(*it)->is_alive_) {
			delete (*it);
			it = p1_bullet_list_.erase(it);
			continue;
		}
		it++;
	}

	it = p2_bullet_list_.begin();
	while (it != p2_bullet_list_.end()) {
		(*it)->update(delta_time);
		if (!(*it)->is_alive_) {
			delete (*it);
			it = p2_bullet_list_.erase(it);
			continue;
		}
		it++;
	}
}

void ScenePlay::update(float delta_time) {
	SceneBase::update(delta_time);

	updateBullet(delta_time);
	check_hit();
}

void ScenePlay::drawBullet()
{
	for (auto obj : p1_bullet_list_) {
		obj->draw();
	}
	for (auto obj : p2_bullet_list_) {
		obj->draw();
	}
	map_manager_->draw_map();
}

void ScenePlay::draw() {
	SceneBase::draw();
	drawBullet();

	DrawStringEx(10, 10, -1, "scene play");
}

