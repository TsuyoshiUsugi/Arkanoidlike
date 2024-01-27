#include "scene_result.h"

#include "game_mamanger.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "tnl_input.h"

class GameManager;

scene_result::scene_result()
{
    mgr = GameManager::GetInstance();
}


void scene_result::update( float delta_time ) {
    SceneBase::update(delta_time);

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        GameManager* mgr = GameManager::GetInstance();
        mgr->changeScene( new SceneTitle() );
    }

}

void scene_result::draw() {
    SceneBase::draw();
    if (mgr->getWinner() == PlayerType::Player1)
    {
        DrawStringEx(show_title_pos.x, show_title_pos.y, -1, "Player1 win");
    }
    else
    {
        DrawStringEx(show_title_pos.x, show_title_pos.y, -1, "Player2 win");
    }
}

