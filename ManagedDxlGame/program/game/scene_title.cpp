#include "../dxlib_ext/dxlib_ext.h"
#include "game_mamanger.h"
#include "scene_title.h"
#include "scene_play.h"
#include <time.h>
#include <string>
#include <numbers>
#include "sound_manager.h"

SceneTitle::SceneTitle()
{
	tnl::AddFontTTF("font/sample.ttf");
	SetFontSize(100);
    ghl_ = LoadGraph("graphics/Title.png");
}

void SceneTitle::Update( float delta_time ) {
	SceneBase::Update(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		std::shared_ptr<GameManager> mgr_ = GameManager::GetInstance();
        SoundManager::GetInstance()->PlaySE(SoundType::Enter);
		mgr_->ChangeScene( std::make_shared<ScenePlay>() );
	}

    current_time_ += delta_time;
    if (current_time_ > flash_time_) {
		current_time_ = 0.0f;
	}
}

void SceneTitle::Draw() {
    SceneBase::Draw();

    // デフォルトの色（白）に戻す
    SetDrawBright(255, 255, 255); // ここで色を白に戻す
    DrawRectGraph(0, 0, 0, 0, 1280, 760, ghl_, false);

 
    ChangeFont("Nikkyou Sans", DX_CHARSET_DEFAULT);

    // "ARKANOID BATTLE" の文字サイズと色を設定
    SetFontSize(100);
    SetDrawBright(255, 0, 0); // 赤色に設定
    DrawStringEx(150, 350, -1, "ARKANOID BATTLE");

    // "PRESS ENTER" の文字サイズを設定
    SetFontSize(30);
    if (current_time_ < flash_time_ / 2) {
        DrawStringEx(500, 600, -1, "PRESS ENTER");
	}
}


