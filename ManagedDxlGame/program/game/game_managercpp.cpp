#include "game_mamanger.h"
#include "player.h"
#include "bullet.h"
#include "scene_title.h"
#include "scene_play.h"

GameManager::GameManager() {

	process_scene_ = new SceneTitle() ;
	setWinner(PlayerType::None);
}

GameManager::~GameManager() {
}

GameManager* GameManager::GetInstance() {
	static GameManager* instance = nullptr;
	if (!instance) instance = new GameManager();
	return instance;
}

void GameManager::setWinner(PlayerType winner)
{
	winner_ = winner;
}

PlayerType GameManager::getWinner()
{
	return winner_;
}


void GameManager::Destroy() {
	delete GetInstance() ;
}

void GameManager::update(float delta_time) {

	process_scene_->update(delta_time);

}

void GameManager::draw() {

	process_scene_->draw();

}

void GameManager::changeScene(SceneBase* scene) {
	if (process_scene_ != nullptr) {
		delete process_scene_;
		process_scene_ = nullptr;
	}
	process_scene_ = scene;
}
