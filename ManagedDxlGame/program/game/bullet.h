#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"
#include "player.h"

// �o���b�g�N���X( �h���N���X )
class Bullet : public Object {
private:
	tnl::Vector3 dir_;
	float speed_ = 10;
	PlayerType player_type_;
public:
	Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir, PlayerType shoot_playerType);
	void update(float delta_time) override ;
	void draw() override ;
};
