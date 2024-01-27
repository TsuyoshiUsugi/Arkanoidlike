#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class in_game_block;

class map_manager
{
private:
    //ロードしたマップの情報
    std::vector<std::vector<int>> map_csv_ ;
    //ブロックをロードするパス
    std::vector<std::string> block_graphic_paths_ = std::vector<std::string>
    {
        "graphics/block.png",
    };

    //ブロックの配置開始位置
    tnl::Vector2i block_start_pos_ = {300, 0};
    int vert_block_num_ = 15;
    int hori_block_num_ = 18;
    int vert_block_space_ = 60;  //各ブロックサイズは30*50
    int hori_block_space_ = 40;

public:
    //保持しているブロック
    std::vector<std::shared_ptr<in_game_block>> blocks_;
    void LoadMap();
    void DrawMap();
};


