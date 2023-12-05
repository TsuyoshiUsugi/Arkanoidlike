#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class in_game_block;

class map_manager
{
private:
    //ロードしたマップの情報
    std::vector<std::vector<int>> map_csv_ ;
    //保持しているブロック
    std::vector<std::shared_ptr<in_game_block>> blocks_;
    //ブロックをロードするパス
    std::vector<std::string> block_graphic_paths_ = std::vector<std::string>
    {
        "graphics/block.png",
    };

    //各ブロックの間の値
    int vert_block_space_ = 60;  //各ブロックサイズは30*50
    int hori_block_space_ = 40;

public:
    void load_map();
    void draw_map();
};


