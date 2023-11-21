#include "scene_result.h"

#include "game_mamanger.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "tnl_input.h"

class GameManager;

void scene_result::update( float delta_time ) {
    SceneBase::update(delta_time);

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        GameManager* mgr = GameManager::GetInstance();
        mgr->changeScene( new SceneTitle() );
    }

}

void scene_result::draw() {
    SceneBase::draw();
    DrawStringEx(10, 10, -1, "scene Result");
}

