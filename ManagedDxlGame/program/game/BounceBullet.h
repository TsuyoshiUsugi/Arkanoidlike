#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "BulletBase.h"
#include "player.h"

class BounceBullet : public BulletBase
{
	using BulletBase::BulletBase;
public:
	void update(float delta_time) override;
	void draw() override;
};

