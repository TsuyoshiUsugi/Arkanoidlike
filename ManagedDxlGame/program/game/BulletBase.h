#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

class BulletBase : public Object
{
public:
	tnl::Vector3 dir_;
	float speed_ = 10;
	BulletBase(const tnl::Vector3& spawn_pos, const tnl::Vector3& dir) 
	{
		pos_ = spawn_pos;
		dir_ = dir;
	};
	virtual void update(float delta_time) = 0;
	virtual void draw() = 0;
};

