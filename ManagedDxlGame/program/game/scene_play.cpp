#include "../dxlib_ext/dxlib_ext.h"
#include "scene_play.h"
#include "player.h"
#include "bullet.h"
#include "game_mamanger.h"
#include "in_game_block.h"
#include "scene_result.h"
#include "item_block.h"
#include "bounce_shoot.h"
#include "explode_effect.h"

ScenePlay::ScenePlay() {
	SetDrawBright(255, 255, 255); // ここで色を白に戻す
	player_1_ = std::make_shared<Player>(PlayerType::Player1);
	objects_.emplace_back( player_1_ );
	player_2_ = std::make_shared<Player>(PlayerType::Player2);
	objects_.emplace_back( player_2_ );
	map_manager_ = std::make_shared<map_manager>();
	map_manager_->LoadMap();
}

bool ScenePlay::ExplodeSequence(float delta_time)
{
	ExplodeEffect explode_effect;
	tnl::Vector3 pos = { 100, 100, 0 };
	//TNL_SEQ_CO_TIM_YIELD_RETURN(0.5f, delta_time, [&]() {
	//	// ここに爆発の処理を書く
	//	explode_effect.Draw(0, pos);
	//	});

	//TNL_SEQ_CO_TIM_YIELD_RETURN(0.5f, delta_time, [&]() {
	//	// ここに爆発の処理を書く
	//	explode_effect.Draw(1, pos);
	//	});
	//
	//TNL_SEQ_CO_TIM_YIELD_RETURN(0.5f, delta_time, [&]() {
	//	// ここに爆発の処理を書く
	//	explode_effect.Draw(2, pos);
	//	});
	//
	//TNL_SEQ_CO_TIM_YIELD_RETURN(0.5f, delta_time, [&]() {
	//	// ここに爆発の処理を書く
	//	explode_effect.Draw(3, pos);
	//	});
	has_exploded_ = true;
	TNL_SEQ_CO_END;
}

//各プレイヤーと弾の当たり判定を行う
//弾の当たり判定の後、弾と各ブロックの当たり判定を行う
void ScenePlay::CheckHit() {
	if (winner_ != PlayerType::None) {
		return;
	}
	// オブジェクトのアップデート処理
	auto bullet_it = p1_bullet_list_.begin();
	PlayerType winner = PlayerType::None;

	while (bullet_it != p1_bullet_list_.end() && winner == PlayerType::None) {
		auto bullet_pos = (*bullet_it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(bullet_pos.x, bullet_pos.y, player_2_->pos_.x, player_2_->pos_.y, player_2_->width_, player_2_->hight_))
		{
			//当たり判定を行う
			winner_ = PlayerType::Player1;
			return;
		}
		auto block_it = map_manager_->blocks_.begin();
		while (block_it != map_manager_->blocks_.end())
		{
			auto block_pos = (*block_it)->pos_;
			auto block_size = (*block_it)->size_;
			if (tnl::IsIntersectPointRect(bullet_pos.x, bullet_pos.y, block_pos.x + block_size.x / 2, block_pos.y + block_size.y / 2, block_size.x, block_size.y))
			{
				//当たり判定を行う
				PlayerType hit_player = PlayerType::Player1;
				(*block_it)->Hit(hit_player);
				map_manager_->blocks_.erase(block_it);
				(*bullet_it)->is_alive_ = false;
				break;
			}
			block_it++;
		}
		bullet_it++;
	}

	bullet_it = p2_bullet_list_.begin();

	while (bullet_it != p2_bullet_list_.end() && winner == PlayerType::None) {
		auto bullet_pos = (*bullet_it)->pos_;	//弾丸の位置
		if (tnl::IsIntersectPointRect(bullet_pos.x, bullet_pos.y, player_1_->pos_.x, player_1_->pos_.y, player_1_->width_, player_1_->hight_)) {	//当たり判定を行う
			winner_ = PlayerType::Player2;
			return;
		}
		auto block_it = map_manager_->blocks_.begin();
		while (block_it != map_manager_->blocks_.end())
		{
			auto block_pos = (*block_it)->pos_;
			auto block_size = (*block_it)->size_;
			if (tnl::IsIntersectPointRect(bullet_pos.x, bullet_pos.y, block_pos.x + block_size.x / 2, block_pos.y + block_size.y / 2, block_size.x, block_size.y))
			{
				//当たり判定を行う
				PlayerType hit_player = PlayerType::Player2;
				(*block_it)->Hit(hit_player);
				map_manager_->blocks_.erase(block_it);
				(*bullet_it)->is_alive_ = false;
				break;
			}
			block_it++;
		}
		bullet_it++;
	}

	auto obj_it = objects_.begin();

	while (obj_it != objects_.end()) {	//アイテムブロックの当たり判定
		std::shared_ptr<ItemBlock> item_block_ptr = std::dynamic_pointer_cast<ItemBlock>(*obj_it);
		if (item_block_ptr) {
			if (tnl::IsIntersectRect(item_block_ptr->pos_, item_block_ptr->size_.x, item_block_ptr->size_.y,
				player_1_->pos_, player_1_->width_, player_1_->hight_))
			{	//プレイヤーの１の判定
				auto dir = tnl::Vector3(1, (float)GetRand(2) - 1, 0);
				player_1_->AddShootMethod(new BounceShoot(dir));
				objects_.erase(obj_it);
				break;
			}
			else if (tnl::IsIntersectRect(item_block_ptr->pos_, item_block_ptr->size_.x, item_block_ptr->size_.y,
				player_2_->pos_, player_2_->width_, player_2_->hight_))
			{	//プレイヤーの２の判定
				auto dir = tnl::Vector3(-1, (float)GetRand(2) - 1, 0);
				player_2_->AddShootMethod(new BounceShoot(dir));
				objects_.erase(obj_it);
				break;
			}
		}

		obj_it++;
	}
}

void ScenePlay::SpawnItemBlock(int ghl, tnl::Vector3 pos, PlayerType player_type)
{
	auto dir = tnl::Vector3(1, 0, 0);
	//ブロックを生成する
	if (player_type == PlayerType::Player1)
	{
		dir *= -1;
	}

	auto block = new ItemBlock(ghl, pos, dir);
	objects_.emplace_back(block);
}

//弾丸を生成する
void ScenePlay::SpawnBullet( tnl::Vector3& spawn_pos, tnl::Vector3& dir, bool isP1Shot) {
	
	if (isP1Shot)
	{
		auto bullet = new Bullet(spawn_pos, dir, PlayerType::Player1);
		p1_bullet_list_.emplace_back( bullet );
	}
	else
	{
		auto bullet = new Bullet(spawn_pos, dir, PlayerType::Player2);
		p2_bullet_list_.emplace_back( bullet );
	}
}

ScenePlay scene_play;

void ScenePlay::UpdateBullet(float delta_time)
{
	if (winner_ != PlayerType::None) {
		on_clear_sequence_.Update(delta_time);

		if (has_exploded_) {
			std::shared_ptr<GameManager> mgr_ = GameManager::GetInstance();
			mgr_->SetWinner(winner_);
			mgr_->ChangeScene(std::make_shared<SceneResult>());
		}
		return;
	}
	auto it = p1_bullet_list_.begin();
	while (it != p1_bullet_list_.end()) {
		(*it)->Update(delta_time);
		if (!(*it)->is_alive_) {
			it = p1_bullet_list_.erase(it);
			continue;
		}
		it++;
	}

	it = p2_bullet_list_.begin();
	while (it != p2_bullet_list_.end()) {
		(*it)->Update(delta_time);
		if (!(*it)->is_alive_) {
			it = p2_bullet_list_.erase(it);
			continue;
		}
		it++;
	}
}

void ScenePlay::Update(float delta_time) {
	SceneBase::Update(delta_time);
	UpdateBullet(delta_time);
	CheckHit();
}

void ScenePlay::DrawBullet()
{
	for (auto& obj : p1_bullet_list_) {
		obj->Draw();
	}
	for (auto& obj : p2_bullet_list_) {
		obj->Draw();
	}
	map_manager_->DrawMap();
}

void ScenePlay::Draw() {
	SceneBase::Draw();
	DrawBullet();
	DrawHelp();
}

void ScenePlay::DrawHelp()
{
	DrawStringEx(0, 600, -1, "W/S");
	DrawStringEx(1000, 600, -1, "↑/↓");
}

