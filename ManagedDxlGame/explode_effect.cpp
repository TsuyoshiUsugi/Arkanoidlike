#include "explode_effect.h"

ExplodeEffect::ExplodeEffect()
{
	for (int i = 0; i < 4; i++)
	{
		ghls_explode_[i] = LoadGraph(files[i].c_str());
	}
}

void ExplodeEffect::Draw(int ghl_num, tnl::Vector3 pos)
{
	DrawRectGraph(pos.x, pos.y, 0, 0, 32, 32, ghls_explode_[ghl_num], false);
}