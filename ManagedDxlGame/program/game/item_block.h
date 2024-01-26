#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

/// <summary>
/// インゲーム中にブロックを破壊すると破壊したプレイヤーに向かって落ちてくるアイテムブロック
/// </summary>
class item_block : public Object {
public:
    int ghl_;    //グラフィックハンドル
    tnl::Vector3 pos_;
    tnl::Vector2i size_ = { 30, 50 }; //サイズは30*50で固定
    tnl::Vector3 move_dir_ = { 1, 0, 0 };
    float speed_ = 5;

    item_block(const int ghl, const tnl::Vector3 pos, tnl::Vector3 move_dir_)
    {
        pos_ = pos;
        ghl_ = ghl;
        move_dir_ = move_dir_;
    }

    void update(float delta_time) override;
    void draw() override;
};