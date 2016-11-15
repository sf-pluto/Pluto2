#include "UserObjectManager.h"
#include "../Lua/LuaBindDirectX.h"

LuaXPtr UserObjectManager::addLuaData(const char *filename){
	LuaXPtr buf( new LuaBindDirectX( filename ) );
	mMap.insert( std::make_pair( filename , buf ) );
	return buf;
}

LuaXPtr UserObjectManager::findLuaData(const char *filename){
	LuaXMap::iterator it;
	it = mMap.find( filename );
	return it == mMap.end() ? addLuaData( filename ) : (*it).second;
}