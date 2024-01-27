#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "player.h"

//XY座標となんの画像を表示するかの情報を持つブロッククラス
class in_game_block
{
    int ghl_;    //グラフィックハンドル

public:
    tnl::Vector3 pos_;
    tnl::Vector2i size_ = {30, 50}; //サイズは30*50で固定
    in_game_block(const int ghl,const tnl::Vector3 pos)
    {
        pos_ = pos;
        ghl_ = ghl;
    }

public:
    void Draw();
    void Hit(PlayerType player_type);
};