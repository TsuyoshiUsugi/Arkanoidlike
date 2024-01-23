#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "shoot_method_base.h"

class BounceShoot : public ShootMethodBase
{
public:
	void shoot(tnl::Vector3 pos, PlayerType player_type) override;
};

