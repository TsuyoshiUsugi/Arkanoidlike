#include "scene_base.h"
#include "object.h"

void SceneBase::Update(float delta_time) {
	// オブジェクトのアップデート処理
	auto it = objects_.begin();
	while (it != objects_.end()) {
		(*it)->Update(delta_time);
		if (!(*it)->is_alive_) {
			it = objects_.erase(it);
			continue;
		}
		it++;
	}
}

void SceneBase::Draw() {
	for (auto& obj : objects_) {
		obj->Draw();
	}
}
