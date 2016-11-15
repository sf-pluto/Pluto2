#ifndef INCLUDED_OBJECT_GAMEOBJECTGROUP_H
#define INCLUDED_OBJECT_GAMEOBJECTGROUP_H

#include <list>
#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;

namespace Object{

class GameObject;
class Image;
class Figure;

class GameObjectGroup{
public:
	typedef boost::shared_ptr< GameObject > ObjPtr;
	GameObjectGroup();
	~GameObjectGroup();

	void createObject( const Image& image , float x , float y , float a , float s );
	void setAction( const string& str );
	void setVisible( bool val );
	void setHP( int val );
	void addObject( const GameObject& ref );
	void addHitArea( Figure* area );
	void setFunction( const string& str );
	// void setFunction( luabind::adl::object* obj );
	void doFunction();
	int count();
	const list< ObjPtr >& getObjectList() const;
private:
	// bool mUsingRef;
	list< ObjPtr > mObjectList;
	//luabind::adl::object* mObjectRef;
	string mFunction;
};

}

#endif //#ifndef INCLUDED_OBJECT_GAMEOBJECTGROUP_H