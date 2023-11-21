#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class map_Loader
{
    std::vector<std::vector<int>> map_csv ;
    std::Vec block
public:
    void LoadMap();
};

//XY座標となんの画像を表示するかの情報を持つブロッククラス
class block
{
    tnl::Vector3 pos_;
    int ghl;    //グラフィックハンドル
    
};
