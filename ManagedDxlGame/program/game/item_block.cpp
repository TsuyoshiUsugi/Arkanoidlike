#include "item_block.h"

void item_block::update(float delta_time)
{
	DrawRectGraph(pos_.x, pos_.y, 0, 0, size_.x, size_.y, ghl_, false);
	DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, GetColor(255, 255, 255), false);
}

void item_block::draw()
{

}