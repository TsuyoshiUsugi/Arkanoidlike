#include "program/game/BounceBullet.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "program/game/BulletBase.h"

// �o���b�g�A�b�v�f�[�g
void BounceBullet::update(float delta_time) {
	// �ړ������Ɖ�ʊO�ɏo���琶���t���O off
	pos_ += dir_ * speed_;
	if (pos_.y < 0) is_alive_ = false;
}

// �o���b�g�`��
void BounceBullet::draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
