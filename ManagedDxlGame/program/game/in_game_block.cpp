#include "in_game_block.h"

void in_game_block::draw()
{
    DrawRectGraph(pos_->x, pos_->y, 0, 0, size_->x, size_->y, ghl_, false);
}
