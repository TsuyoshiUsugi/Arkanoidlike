#include "map_manager.h"

//Map情報をロードします
void map_manager::LoadMap()
{
    map_csv_ = tnl::LoadCsv<int>("map.csv");

    for (int i = 0; i < map_csv_.size(); ++i) {
        for (int k = 0; k < map_csv_[i].size(); ++k) {
            if (0 == map_csv_[i][k]) continue;
            tnl::Vector3 pos;
            // pos.x = { 100.0f + k * Block::CHIP_SIZE };
            // pos.y = { 100.0f + i * Block::CHIP_SIZE };
            // blocks.emplace_back( new Block(pos) );
            
        }
    }
}

//Mapの描画処理
void map_manager::DrawMap()
{
    
}
