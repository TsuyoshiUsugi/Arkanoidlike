﻿#include "map_manager.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "in_game_block.h"

//Map情報をロードします
void map_manager::LoadMap()
{
    map_csv_ = tnl::LoadCsv<int>("map.csv");

    // for (int i = 0; i < map_csv_.size(); ++i) {
    //     for (int k = 0; k < map_csv_[i].size(); ++k) {
    //         if (0 == map_csv_[i][k]) continue;
    //         tnl::Vector3 pos;
    //         pos.x = { 100.0f + k * Block::CHIP_SIZE };
    //         pos.y = { 100.0f + i * Block::CHIP_SIZE };
    //         blocks.emplace_back( new Block(pos) );
    //         
    //     }
    // }

    blocks_ = std::vector<std::shared_ptr<in_game_block>>();

    
    //テスト用のマップ生成(5*5)
    for (int i = 0; i < hori_block_num_; ++i) //横
    {
        for (int k = 0; k < vert_block_num_; k++) //縦
        {
            auto hdl = LoadGraph(block_graphic_paths_[0].c_str());
            auto pos = tnl::Vector3(block_start_pos_.x + hori_block_space_ * i, 0 + vert_block_space_ * k, 0);
            auto block = std::make_shared<in_game_block>(hdl, pos);
            
            blocks_.emplace_back(block);
        }
    }
}

//Mapの描画処理
void map_manager::DrawMap()
{
    for (const auto& block : blocks_) {
        block->Draw();
    }
}
