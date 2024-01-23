#include "BounceBullet.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"

void BounceBullet::update(float delta_time)
{
	pos_ += move_dir_ * speed_ * delta_time;
}

void BounceBullet::draw()
{
	DrawCircle(pos_.x, pos_.y, 10, GetColor(255, 255, 255), true);
}

// バレットコンストラクタ
// arg1... スポーン座標
Bullet::Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir) {
	pos_ = spawn_pos;
	dir_ = dir;
}

// バレットアップデート
void BounceBullet::update(float delta_time) {
	// 移動処理と画面外に出たら生存フラグ off
	pos_ += dir_ * speed_;
	if (pos_.y < 0) is_alive_ = false;
}

// バレット描画
void Bullet::draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
