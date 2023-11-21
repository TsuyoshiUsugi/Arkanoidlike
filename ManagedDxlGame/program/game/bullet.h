#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

// バレットクラス( 派生クラス )
class Bullet : public Object {
private:
	tnl::Vector3 dir_;
public:
	Bullet(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir);
	void update(float delta_time) override ;
	void draw() override ;
};
