#include "item_block.h"

void ItemBlock::update(float delta_time)
{
	if (pos_.x < 0 || pos_.x > 1500) is_alive_ = false;
	pos_ += move_dir_ * speed_;
}

void ItemBlock::draw()
{
	DrawRectGraph(pos_.x, pos_.y, 0, 0, size_.x, size_.y, ghl_, false);
	DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, GetColor(255, 255, 255), false);
}