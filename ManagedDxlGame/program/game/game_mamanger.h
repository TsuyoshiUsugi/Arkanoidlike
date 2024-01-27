#pragma once
#include "player.h"
#include "../dxlib_ext/dxlib_ext.h"

// 前方宣言
class Object;
class SceneBase;

// シングルトン
class GameManager {
private:
	PlayerType winner_ = PlayerType::None;
public:
	GameManager();

	static std::shared_ptr<GameManager> GetInstance();
	static void Destroy();

	void ChangeScene(std::shared_ptr<SceneBase> scene);
	void SetWinner(PlayerType winner);
	PlayerType GetWinner();

	void Update(float delta_time);
	void Draw();


	std::list<Object*> objects_;
	std::shared_ptr<SceneBase> process_scene_ = nullptr;
};


