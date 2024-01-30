#include "scene_result.h"

#include "game_mamanger.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "scene_title.h"
#include "tnl_input.h"

class GameManager;

SceneResult::SceneResult()
{
    mgr_ = GameManager::GetInstance();
}


void SceneResult::Update( float delta_time ) {
    SceneBase::Update(delta_time);

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        std::shared_ptr<GameManager> mgr_ = GameManager::GetInstance();
        mgr_->ChangeScene( std::make_shared<SceneTitle>() );
    }

}

void SceneResult::Draw() {
    SceneBase::Draw();
    if (mgr_->GetWinner() == PlayerType::Player1)
    {
        DrawStringEx(show_title_pos.x, show_title_pos.y, -1, "Player1 win");
    }
    else
    {
        DrawStringEx(show_title_pos.x, show_title_pos.y, -1, "Player2 win");
    }
    // "PRESS ENTER" の文字サイズを設定
    SetFontSize(30);
    DrawStringEx(500, 600, -1, "PRESS ENTER");
    
}

