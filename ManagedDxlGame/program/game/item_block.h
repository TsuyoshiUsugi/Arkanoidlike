#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "object.h"

/// <summary>
/// �C���Q�[�����Ƀu���b�N��j�󂷂�Ɣj�󂵂��v���C���[�Ɍ������ė����Ă���A�C�e���u���b�N
/// </summary>
class ItemBlock : public Object {
public:
    int ghl_;    //�O���t�B�b�N�n���h��
    tnl::Vector3 pos_;
    tnl::Vector2i size_ = { 30, 50 }; //�T�C�Y��30*50�ŌŒ�
    tnl::Vector3 move_dir_;
    float speed_ = 5;

    ItemBlock(const int ghl, const tnl::Vector3 pos, tnl::Vector3 move_dir)
    {
        pos_ = pos;
        ghl_ = ghl;
        move_dir_ = move_dir;
    }

    void update(float delta_time) override;
    void draw() override;
};