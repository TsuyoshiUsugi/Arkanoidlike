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
    item_block(const int ghl, const tnl::Vector3 pos)
    {
        pos_ = pos;
        ghl_ = ghl;
    }

    void update(float delta_time) override;
    void draw() override;
    void Hit();
};