#include "UserObject.h"
#include "../Lua/LuaBindDirectX.h"
#include "UserObjectManager.h"

namespace Object{

UserObject::UserObject() : mScript(){
}

UserObject::UserObject( const char* filename ) : mScript( UserObjectManager::instance()->findLuaData( filename ) ){
	mScript->initLua();
}

UserObject::~UserObject(){
}

void UserObject::update(){
	mScript->doLuaLoop();
}

}