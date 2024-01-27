#include "bullet.h"
#include "player.h"

// バレットコンストラクタ
// arg1... スポーン座標
Bullet::Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir, PlayerType shoot_playerType) {
	pos_ = spawn_pos;
	dir_ = dir;
	player_type_ = shoot_playerType;
}

// バレットアップデート
void Bullet::Update(float delta_time) {
	// 移動処理と画面外に出たら生存フラグ off
	pos_ += dir_ * speed_;
	if (pos_.x < 0 || pos_.x > 1500) is_alive_ = false;
	if (pos_.y < 0 || pos_.y > 700) dir_.y *= -1;
}

// バレット描画
void Bullet::Draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
