#pragma once
#include "scene_base.h"

class scene_result : public SceneBase
{
public :
    void update(float delta_time) override;
    void draw() override;
};
