#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class ExplodeEffect
{
	int ghls_explode_[4];
	std::string files[4] = {
	"graphics/Effect1",
	"graphics/Effect2",
	"graphics/Effect3",
	};

public:
	ExplodeEffect();
	void Draw(int ghl_num, tnl::Vector3 pos);
};

