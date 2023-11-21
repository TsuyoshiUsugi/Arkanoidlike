#include "map_Loader.h"

//Map情報をロードします
void map_Loader::LoadMap()
{
    map_csv = tnl::LoadCsv<int>("map.csv");

    for (int i = 0; i < map_csv.size(); ++i) {
        for (int k = 0; k < map_csv[i].size(); ++k) {
            if (0 == map_csv[i][k]) continue;
            tnl::Vector3 pos;
            // pos.x = { 100.0f + k * Block::CHIP_SIZE };
            // pos.y = { 100.0f + i * Block::CHIP_SIZE };
            // blocks.emplace_back( new Block(pos) );
            
        }
    }
}