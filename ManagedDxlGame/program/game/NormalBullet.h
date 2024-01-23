#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"
#include "BulletBase.h"

// バレットクラス( 派生クラス )
class NormalBullet : public BulletBase {
	using BulletBase::BulletBase;
private:
	tnl::Vector3 dir_;
	float speed_ = 10;
public:
	void update(float delta_time) override ;
	void draw() override ;
};
