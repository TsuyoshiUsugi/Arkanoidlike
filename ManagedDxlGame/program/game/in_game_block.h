#pragma once
#include "../dxlib_ext/dxlib_ext.h"

//XY座標となんの画像を表示するかの情報を持つブロッククラス
class in_game_block
{
    std::shared_ptr<tnl::Vector3> pos_;
    std::shared_ptr<tnl::Vector2i> size_ = std::make_shared<tnl::Vector2i>(30, 50); //サイズは30*50で固定
    int ghl_;    //グラフィックハンドル
    public:
    in_game_block(const int ghl,const std::shared_ptr<tnl::Vector3>& pos)
    {
        pos_ = pos;
        ghl_ = ghl;
    }
};