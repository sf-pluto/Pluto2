#ifndef INCLUDED_SCENE_SCENE_H
#define INCLUDED_SCENE_SCENE_H

#include <boost/utility.hpp>
#include <string>

class LuaBindDirectX;

namespace PlScene{

class Scene : private boost::noncopyable{
public:
	Scene();
	Scene( const std::string& filename );
	~Scene();

	Scene* update();
private:
	LuaBindDirectX* mScript;
};

}

#endif //#ifndef INCLUDED_SCENE_SCENE_H