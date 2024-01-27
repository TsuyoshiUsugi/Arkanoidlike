#pragma once
#include "game_mamanger.h"
#include "scene_base.h"

class SceneResult : public SceneBase
{
private:
    std::shared_ptr<GameManager> mgr_;
    tnl::Vector3 show_title_pos = {500, 350, 0};
public :
    SceneResult();
    void Update(float delta_time) override;
    void Draw() override;
};
