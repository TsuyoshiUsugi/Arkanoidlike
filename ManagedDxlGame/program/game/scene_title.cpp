#include "../dxlib_ext/dxlib_ext.h"
#include "game_mamanger.h"
#include "scene_title.h"
#include "scene_play.h"

void SceneTitle::update( float delta_time ) {
	SceneBase::update(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		GameManager* mgr = GameManager::GetInstance();
		mgr->changeScene( new ScenePlay() );
	}

}

void SceneTitle::draw() {
	SceneBase::draw();
	SetFontSize(100);
	DrawStringEx(show_result_pos.x, show_result_pos.y, -1, "ARKANOID BATTLE");
}

