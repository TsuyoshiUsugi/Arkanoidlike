#pragma once
#include "scene_base.h"

class SceneTitle : public SceneBase {
private:
	tnl::Vector3 show_title_pos = { 200, 350, 0 };
	int ghl_;
public :
	SceneTitle();
	void update( float delta_time ) override ;
	void draw() override ;

};

