#pragma once
#include "../dxlib_ext/dxlib_ext.h"

// �I�u�W�F�N�g�N���X( ���N���X )
class Object {
public:
	virtual ~Object(){}

	// �����t���O
	bool is_alive_ = true;

	tnl::Vector3 pos_;

	virtual void update(float delta_time) {} ;
	virtual void draw() {} ;
};
