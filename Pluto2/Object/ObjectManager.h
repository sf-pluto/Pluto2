#ifndef INCLUDED_OBJECT_OBJECTMANAGER_H
#define INCLUDED_OBJECT_OBJECTMANAGER_H

#include "../class/singleton.h"
#include <list>

using namespace std;

namespace Object{

class GameObject;
class ObjectObserver;

class ObjectManager : public Singleton< ObjectManager >{
public:
	ObjectManager();

	void update();
	ObjectObserver* registerObject( GameObject* ptr );
private:
	list< ObjectObserver* > mList;
};

class ObjectObserver{
public:
	ObjectObserver( GameObject* ptr );
	~ObjectObserver();

	GameObject* mPtr;
	bool mIsAlive;
};

}

#endif //#ifndef INCLUDED_OBJECT_OBJECTMANAGER_H