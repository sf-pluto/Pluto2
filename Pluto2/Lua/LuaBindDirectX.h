#ifndef INCLUDED_LUA_LUABINDDIRECTX_H
#define INCLUDED_LUA_LUABINDDIRECTX_H

#include <boost/utility.hpp>
#include <string>

struct lua_State;

class LuaBindDirectX : private boost::noncopyable{
public:
	LuaBindDirectX();
	LuaBindDirectX( const char* filename );
	~LuaBindDirectX();

	void initLua();
	void doLuaLoop();
private:
	lua_State* mLua;

	void reloadScript();
	std::string mFilename;
};

#endif //#ifndef INCLUDED_LUA_LUABINDDIRECTX_H