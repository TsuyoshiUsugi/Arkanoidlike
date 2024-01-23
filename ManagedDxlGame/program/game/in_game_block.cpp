#include "in_game_block.h"

void in_game_block::draw()
{
    DrawRectGraph(pos_.x, pos_.y, 0, 0, size_.x, size_.y, ghl_, false);
    DrawBox(pos_.x, pos_.y, pos_.x + size_.x, pos_.y + size_.y, GetColor(255, 255, 255), false);
}

void in_game_block::Hit()
{
    //ブロックが当たった時の処理

}
