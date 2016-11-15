#ifndef INCLUDED_SCENE_PARENT_H
#define INCLUDED_SCENE_PARENT_H

#include "../class/Singleton.h"
#include <string>

namespace PlScene{

class Scene;

class Parent : public Singleton< Parent >{
public:
	Parent();
	~Parent();

	bool update();
	void quit();
	void setScene( const std::string& filename );
	std::string& getNextScene();
	void setNextScene( const std::string& str );
private:
	bool mEnded;
	Scene* mScene;
	std::string mNextScene;
};

}

#endif //#ifndef INCLUDED_SCENE_PARENT_H