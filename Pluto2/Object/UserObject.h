#ifndef INCLUDED_OBJECT_USEROBJECT_H
#define INCLUDED_OBJECT_USEROBJECT_H

#include <boost/shared_ptr.hpp>

class LuaBindDirectX;

namespace Object{

class UserObject{
public:
	typedef boost::shared_ptr< LuaBindDirectX > LuaXPtr;
	UserObject();
	UserObject( const char* filename );
	~UserObject();

	void update();
private:
	LuaXPtr mScript;
};

}

#endif //#ifndef INCLUDED_OBJECT_USEROBJECT_H