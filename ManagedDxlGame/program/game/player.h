#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

//�v���C���[�̎�ނ𔻕ʂ���
enum class PlayerType { Player1, Player2, };

// �v���C���[�N���X( �h���N���X )
class Player : public Object {
private:
	tnl::Vector3 left_player_start_vector3_pos_ = { 300, 500, 0 };
	tnl::Vector3 right_player_start_vector3_pos_ = { 600, 500, 0 };
	tnl::Vector3 left_shoot_bullet_pos_ = {-20, 0, 0};
	tnl::Vector3 right_shoot_bullet_pos_ = {20, 0, 0};
	tnl::Vector3 dir_ = {1, 0, 0};
	PlayerType playerType_;
public:
	Player(PlayerType playerType) {
		playerType_ = playerType;

		if (playerType_ == PlayerType::Player1)
			pos_ = left_player_start_vector3_pos_;
		else
		{
			pos_ = right_player_start_vector3_pos_;
			dir_ *= -1;	//���΂ɂ���
		}
	}

	void ShootBullet();
	void MoveHorizontal();
	void update(float delta_time) override ;
	void draw() override ;
};


