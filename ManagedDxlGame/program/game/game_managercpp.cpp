#include "game_mamanger.h"
#include "player.h"
#include "bullet.h"
#include "scene_title.h"
#include "scene_play.h"

GameManager::GameManager() {
	process_scene_ = std::make_shared<SceneTitle>() ;
	SetWinner(PlayerType::None);
	SetWindowSize(1620, 780);
	SoundManager::GetInstance()->LoadSound();
}

std::shared_ptr<GameManager> GameManager::GetInstance() {
	static std::shared_ptr<GameManager> instance = nullptr;
	if (!instance) instance = std::make_shared<GameManager>();
	return instance;
}

void GameManager::SetWinner(PlayerType winner)
{
	winner_ = winner;
}

PlayerType GameManager::GetWinner()
{
	return winner_;
}


void GameManager::Destroy() {
	//sdelete GetInstance() ;
}

void GameManager::Update(float delta_time) {

	process_scene_->Update(delta_time);

}

void GameManager::Draw() {

	process_scene_->Draw();

}

void GameManager::ChangeScene(std::shared_ptr<SceneBase> scene) {
	if (process_scene_ != nullptr) {
		//delete process_scene_;
		process_scene_ = nullptr;
	}
	process_scene_ = scene;
}
