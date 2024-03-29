#pragma once
#include "../dxlib_ext/dxlib_ext.h"

// オブジェクトクラス( 基底クラス )
class Object {
public:
	virtual ~Object(){}

	// 生存フラグ
	bool is_alive_ = true;

	tnl::Vector3 pos_;
	float width_;
	float hight_;

	virtual void Update(float delta_time) {} ;
	virtual void Draw() {} ;
};
