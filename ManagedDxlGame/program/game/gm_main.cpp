#include <time.h>
#include <string>
#include <numbers>
#include <functional>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "game_mamanger.h"


//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart(){
	srand(time(0));
	SetBackgroundColor( 32, 32, 32 );

	SetFontSize(50);
}


//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {

	GameManager::GetInstance()->Update(delta_time);
	GameManager::GetInstance()->Draw();

	//DrawFpsIndicator({ 10, DXE_WINDOW_HEIGHT - 10, 0 }, delta_time);
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {
	GameManager::Destroy();
}

