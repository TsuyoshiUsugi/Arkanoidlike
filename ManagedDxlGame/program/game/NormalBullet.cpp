#include "NormalBullet.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "BulletBase.h"

// バレットアップデート
void NormalBullet::update(float delta_time) {
	// 移動処理と画面外に出たら生存フラグ off
	pos_ += dir_ * speed_;
	if (pos_.y < 0) is_alive_ = false;
}

// バレット描画
void NormalBullet::draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
