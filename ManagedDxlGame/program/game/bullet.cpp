#include "bullet.h"

// バレットコンストラクタ
// arg1... スポーン座標
Bullet::Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir) {
	pos_ = spawn_pos;
	dir_ = dir;
}

// バレットアップデート
void Bullet::update(float delta_time) {
	// 移動処理と画面外に出たら生存フラグ off
	pos_ += dir_ * speed_;
	if (pos_.x < 0 || pos_.x > 1500) is_alive_ = false;
	if (pos_.y < 0 || pos_.y > 700) dir_.y *= -1;
}

// バレット描画
void Bullet::draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
