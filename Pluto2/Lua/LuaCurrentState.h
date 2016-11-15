#include "../Class/Singleton.h"

struct lua_State;

class LuaCurrentState : public Singleton< LuaCurrentState >{
public:
	LuaCurrentState();
	lua_State* getState();
	void setState( lua_State* ptr );
private:
	lua_State* mLuaState;
};