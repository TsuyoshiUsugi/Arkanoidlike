#pragma once
#include "game_mamanger.h"
#include "scene_base.h"

class scene_result : public SceneBase
{
private:
    GameManager* mgr;
public :
    scene_result();
    void update(float delta_time) override;
    void draw() override;
};
