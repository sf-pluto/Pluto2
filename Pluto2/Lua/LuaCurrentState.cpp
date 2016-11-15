#include "LuaCurrentState.h"

LuaCurrentState::LuaCurrentState() : mLuaState( NULL ){
}

lua_State* LuaCurrentState::getState(){
	return mLuaState;
}

void LuaCurrentState::setState(lua_State* ptr){
	mLuaState = ptr;
}