#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

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
public:
	Player(PlayerType playerType) {
		playerType_ = playerType;
		width_ = 30;
		hight_ = 50;

		if (playerType_ == PlayerType::Player1)
			pos_ = left_player_start_vector3_pos_;
		else
		{
			pos_ = right_player_start_vector3_pos_;
			dir_ *= -1;	//反対にする
		}
	}

	void ShootBullet();
	void MoveHorizontal();
	void update(float delta_time) override ;
	void draw() override ;
};


