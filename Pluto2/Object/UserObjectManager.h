#ifndef INCLUDED_OBJECT_USEROBJECTMANAGER_H
#define INCLUDED_OBJECT_USEROBJECTMANAGER_H

#include "../Class/singleton.h"
#include <boost/shared_ptr.hpp>
#include <map>

class LuaBindDirectX;

typedef boost::shared_ptr< LuaBindDirectX > LuaXPtr;
typedef std::map< const char* , LuaXPtr > LuaXMap;

class UserObjectManager : public Singleton< UserObjectManager >{
public:
	LuaXPtr addLuaData( const char* filename );
	LuaXPtr findLuaData( const char* filename );
private:
	LuaXMap mMap;
};

#endif //#ifndef INCLUDED_OBJECT_USEROBJECTMANAGER_H