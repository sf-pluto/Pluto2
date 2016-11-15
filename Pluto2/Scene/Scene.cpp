#include "Scene.h"
#include "Parent.h"
#include "../Lua/LuaBindDirectX.h"
#include "../PlUtils.h"

namespace PlScene{

Scene::Scene() : mScript( NULL ){
}

Scene::Scene(const std::string& filename) : mScript( new LuaBindDirectX( filename.c_str() ) ){
	mScript->initLua();
}

Scene::~Scene(){
	if( mScript != NULL ){
		SAFE_DELETE( mScript );
	}
}

Scene* Scene::update(){
	mScript->doLuaLoop();
	std::string name = Parent::instance()->getNextScene();
	Scene* next = this;
	if( !name.empty() ){
		next = new Scene( name );
		Parent::instance()->setNextScene( "" );
	}
	return next;
}

}