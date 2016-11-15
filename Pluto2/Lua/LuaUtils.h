#ifndef INCLUDED_LUA_LUAUTILS_H
#define INCLUDED_LUA_LUAUTILS_H

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include <luabind/luabind.hpp>

#include <stdio.h>

extern void setConstant( lua_State* L , const char* name , lua_Number num );
extern lua_State* initLuaBind();

#endif //#ifndef INCLUDED_LUA_LUAUTILS_H