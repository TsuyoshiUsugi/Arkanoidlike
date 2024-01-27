#include "scene_base.h"
#include "object.h"

void SceneBase::Update(float delta_time) {
	// �I�u�W�F�N�g�̃A�b�v�f�[�g����
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
