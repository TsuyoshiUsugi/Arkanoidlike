#pragma once
#include <list>

class Object ;

class SceneBase {
public :
	virtual ~SceneBase(){}
	virtual void update(float delta_time);
	virtual void draw();

	std::list<Object*> objects_ ;
};

