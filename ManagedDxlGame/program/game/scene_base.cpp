#include "scene_base.h"
#include "object.h"

void SceneBase::update(float delta_time) {
	// オブジェクトのアップデート処理
	auto it = objects_.begin();
	while (it != objects_.end()) {
		(*it)->update(delta_time);
		if (!(*it)->is_alive_) {
			delete (*it);
			it = objects_.erase(it);
			continue;
		}
		it++;
	}
}

void SceneBase::draw() {
	for (auto obj : objects_) {
		obj->draw();
	}
}
