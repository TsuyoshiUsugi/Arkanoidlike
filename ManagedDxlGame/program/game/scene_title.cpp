#include "../dxlib_ext/dxlib_ext.h"
#include "game_mamanger.h"
#include "scene_title.h"
#include "scene_play.h"

SceneTitle::SceneTitle()
{
	tnl::AddFontTTF("font/sample.ttf");
	SetFontSize(100);
    ghl_ = LoadGraph("graphics/Title.png");
}

void SceneTitle::update( float delta_time ) {
	SceneBase::update(delta_time);

	if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
		GameManager* mgr = GameManager::GetInstance();
		mgr->changeScene( new ScenePlay() );
	}

}

void SceneTitle::draw() {
    SceneBase::draw();

    // �f�t�H���g�̐F�i���j�ɖ߂�
    SetDrawBright(255, 255, 255); // �����ŐF�𔒂ɖ߂�
    DrawRectGraph(0, 0, 0, 0, 1280, 760, ghl_, false);

 
    ChangeFont("Nikkyou Sans", DX_CHARSET_DEFAULT);

    // "ARKANOID BATTLE" �̕����T�C�Y�ƐF��ݒ�
    SetFontSize(100);
    SetDrawBright(255, 0, 0); // �ԐF�ɐݒ�
    DrawStringEx(150, 350, -1, "ARKANOID BATTLE");

    // "PRESS ENTER" �̕����T�C�Y��ݒ�
    SetFontSize(30);
    DrawStringEx(500, 600, -1, "PRESS ENTER");
}



