#include "Const.h"
#include "../Lua/LuaUtils.h"
#include "../Lua/LuaCurrentState.h"

namespace Object{

Const::Const( float val ) : mValue( val ){
	lua_pushlightuserdata( LuaCurrentState::instance()->getState(), &mValue );
	lua_setglobal( LuaCurrentState::instance()->getState(), "PPPI" );
}


}