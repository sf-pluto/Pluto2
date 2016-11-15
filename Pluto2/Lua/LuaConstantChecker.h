#ifndef INCLUDED_LUA_CONSTANTCHECKER_H
#define INCLUDED_LUA_CONSTANTCHECKER_H

#include "../Class/Singleton.h"
#include <vector>
#include <algorithm>

using namespace std;
class LuaCurrentState;

class LuaConstantChecker : public Singleton< LuaConstantChecker >{
public:
	LuaConstantChecker();
	~LuaConstantChecker();

	void check();
	void add( const char* name, double value );
private:
	typedef pair< const char*, double > Value;

	int mInterval;
	int mCount;
	vector< Value > mConstantName;
	LuaCurrentState* mState;
};

#endif //#ifndef INCLUDED_LUA\CONSTANTCHECKER_H