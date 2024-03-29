#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

/// <summary>
/// インゲーム中にブロックを破壊すると破壊したプレイヤーに向かって落ちてくるアイテムブロック
/// </summary>
class ItemBlock : public Object {
public:
    int ghl_;    //グラフィックハンドル
    tnl::Vector3 pos_;
    tnl::Vector2i size_ = { 30, 50 }; //サイズは30*50で固定
    tnl::Vector3 move_dir_;
    float speed_ = 5;

    ItemBlock(const int ghl, const tnl::Vector3 pos, tnl::Vector3 move_dir)
    {
        pos_ = pos;
        ghl_ = ghl;
        move_dir_ = move_dir;
    }

    void Update(float delta_time) override;
    void Draw() override;
};