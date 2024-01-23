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

// �o���b�g�R���X�g���N�^
// arg1... �X�|�[�����W
Bullet::Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir) {
	pos_ = spawn_pos;
	dir_ = dir;
}

// �o���b�g�A�b�v�f�[�g
void BounceBullet::update(float delta_time) {
	// �ړ������Ɖ�ʊO�ɏo���琶���t���O off
	pos_ += dir_ * speed_;
	if (pos_.y < 0) is_alive_ = false;
}

// �o���b�g�`��
void Bullet::draw() {
	DrawCircle(pos_.x, pos_.y, 3, -1, false);
}
