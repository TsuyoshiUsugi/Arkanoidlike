#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"	

/// <summary>
/// ËŒ‚ˆ—‚ÌŠî’êƒNƒ‰ƒX
/// </summary>
class ShootMethodBase
{
public :
	tnl::Vector3 move_dir_ = {1, 0, 0};
	virtual void shoot(tnl::Vector3 pos, PlayerType player_type) = 0;
};

