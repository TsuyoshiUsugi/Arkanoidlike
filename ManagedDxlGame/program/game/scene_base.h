#pragma once
#include <list>
#include <memory>

class Object ;

class SceneBase {
public :
	virtual ~SceneBase(){}
	virtual void Update(float delta_time);
	virtual void Draw();

	std::list<std::shared_ptr<Object>> objects_ ;
};

