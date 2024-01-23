#pragma once
#include "scene_base.h"

class SceneTitle : public SceneBase {
private:
	tnl::Vector3 show_result_pos = { 300, 350, 0 };
public :
	
	void update( float delta_time ) override ;
	void draw() override ;

};

