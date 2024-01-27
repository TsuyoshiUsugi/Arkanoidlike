#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "shoot_method_base.h"

/// <summary>
/// ’Êí‚Ì’e‚ğ”­Ë‚·‚éƒNƒ‰ƒX
/// </summary>
class NormalShoot : public ShootMethodBase
{
public:
	void Shoot(tnl::Vector3 pos, PlayerType player_type) override;
};

