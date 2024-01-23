#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

class ShootMethodBase;

//プレイヤーの種類を判別する
enum class PlayerType { None, Player1, Player2, };

// プレイヤークラス( 派生クラス )
class Player : public Object {
private:
	tnl::Vector3 left_player_start_vector3_pos_ = { 100, 500, 0 };
	tnl::Vector3 right_player_start_vector3_pos_ = { 1200, 500, 0 };
	tnl::Vector3 left_shoot_bullet_pos_ = {-20, 0, 0};
	tnl::Vector3 right_shoot_bullet_pos_ = {20, 0, 0};
	tnl::Vector3 dir_ = {1, 0, 0};
	PlayerType playerType_;
	std::vector<ShootMethodBase*> shoot_methods_;
public:
	Player(PlayerType playerType);

	void ShootBullet();
	void MoveHorizontal();
	void update(float delta_time) override ;
	void draw() override ;
	void AddShootMethod(ShootMethodBase* shoot_method);
};


