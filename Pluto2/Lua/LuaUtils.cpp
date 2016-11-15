#include "LuaUtils.h"
#include "LuaConstantChecker.h"

void setConstant( lua_State* L , const char* name , lua_Number num ){
	// スタックにプッシュ
	lua_pushnumber( L , num );
	lua_setglobal( L,  name );
	LuaConstantChecker::instance()->add( name , num );
}

lua_State* initLuaBind(){
	lua_State* L = lua_open();
	luabind::open( L );
	return L;
}