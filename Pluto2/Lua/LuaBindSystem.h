#ifndef INCLUDED_LUA_LUABINDSYSTEM_H
#define INCLUDED_LUA_LUABINDSYSTEM_H

#include "../class/Singleton.h"
#include <string>

struct lua_State;
class GameFrame;

class LuaBindSystem : public Singleton< LuaBindSystem >{
public:
	LuaBindSystem();
	void initalize( const char* filename );
	~LuaBindSystem();

	void setGameFrame( GameFrame* ptr );
	void runScript();
	void createScene( const std::string& filename ); 
private:
	lua_State* mLua;
	GameFrame* mGameFrame;

};

#endif //#ifndef INCLUDED_LUA_LUABINDSYSTEM_H