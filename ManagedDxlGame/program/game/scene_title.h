#pragma once
#include "scene_base.h"
#include "../dxlib_ext/dxlib_ext.h"
#include "sound_manager.h"

class SceneTitle : public SceneBase {
private:
	tnl::Vector3 show_title_pos = { 200, 350, 0 };
	int ghl_;
	float flash_time_ = 1.0f; 
	float current_time_ = 0.0f;

public:
	SceneTitle();
	void Update( float delta_time ) override ;
	void Draw() override ;
	bool FlashString(const float delta_time);
};

