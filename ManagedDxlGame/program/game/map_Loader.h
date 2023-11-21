#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class map_Loader
{
    std::vector<std::vector<int>> map_csv ;
public:
    void LoadMap();
};
