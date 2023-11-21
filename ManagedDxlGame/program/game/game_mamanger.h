#pragma once
#include "player.h"
#include "../dxlib_ext/dxlib_ext.h"

// 前方宣言
class Object;
class SceneBase;

// シングルトン
class GameManager {
private:
	PlayerType winner = PlayerType::None;
	GameManager();
	~GameManager();
public:

	static GameManager* GetInstance();
	static void Destroy();

	void changeScene( SceneBase* scene );

	void update(float delta_time);
	void draw();


	std::list<Object*> objects_;
	SceneBase* process_scene_ = nullptr;
};


