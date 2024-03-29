#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "shoot_method_base.h"

/// <summary>
/// 通常の弾を発射するクラス
/// </summary>
class NormalShoot : public ShootMethodBase
{
public:
	void Shoot(tnl::Vector3 pos, PlayerType player_type) override;
};

