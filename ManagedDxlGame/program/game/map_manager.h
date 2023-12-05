#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class block;

class map_manager
{
private:
    std::vector<std::vector<int>> map_csv_ ;
    std::shared_ptr<block> blocks_;
    //std::Vec block
public:
    void LoadMap();
    void DrawMap();
};

//XY座標となんの画像を表示するかの情報を持つブロッククラス
class block
{
    tnl::Vector3 pos_;
    tnl::Vector2i size_;
    int ghl_;    //グラフィックハンドル
public:
    block(int ghl)
    {
        ghl_ = ghl;
    }
};
