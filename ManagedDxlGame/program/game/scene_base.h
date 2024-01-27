#pragma once
#include <list>

class Object ;

class SceneBase {
public :
	virtual ~SceneBase(){}
	virtual void Update(float delta_time);
	virtual void Draw();

	std::list<Object*> objects_ ;
};

