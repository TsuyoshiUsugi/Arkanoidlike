#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "shoot_method_base.h"

/// <summary>
/// �ʏ�̒e�𔭎˂���N���X
/// </summary>
class NormalShoot : public ShootMethodBase
{
public:
	void Shoot(tnl::Vector3 pos, PlayerType player_type) override;
};

