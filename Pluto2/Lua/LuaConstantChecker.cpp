#include "../PlUtils.h"
#include "LuaUtils.h"
#include "LuaConstantChecker.h"
#include "LuaCurrentState.h"
#include <string>

// Debug only?
LuaConstantChecker::LuaConstantChecker() : mInterval( 120 ),
mCount( 0 ),
mState( LuaCurrentState::instance() ){
}

LuaConstantChecker::~LuaConstantChecker(){
}

void LuaConstantChecker::check(){
	if( ++mCount >= mInterval ){
		lua_State* L = mState->getState();
		foreach( Value& v, mConstantName ){
			lua_getglobal( L, v.first );
			if( v.second != lua_tonumber( L, -1 ) ){
				string s = v.first;
				s += " has been changed illegally.";
				HALT( s.c_str() );
			}
			lua_pop( L, 1 );
		}
		mCount = 0;
	}
}

void LuaConstantChecker::add(const char *name, double value){
	mConstantName.push_back( make_pair( name, value ) );
}