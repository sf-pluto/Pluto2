#include "ObjectManager.h"
#include "GameObject.h"
#include "../PlUtils.h"

namespace Object{

ObjectManager::ObjectManager(){
}

ObjectObserver* ObjectManager::registerObject(GameObject* ptr){
	ObjectObserver* obs = new ObjectObserver( ptr );
	mList.push_back( obs );
	return obs;
}

void ObjectManager::update(){
	list< ObjectObserver* >::iterator it = mList.begin();
	while( it != mList.end() ){
		if( (*it)->mIsAlive ){
			(*it)->mPtr->addFrame();
		}else{
			SAFE_DELETE( *it );
			it = mList.erase( it );
			continue;
		}
		it++;
	}
}

ObjectObserver::ObjectObserver(Object::GameObject *ptr) : mPtr( ptr ),
mIsAlive( true ){
}

ObjectObserver::~ObjectObserver(){
}

}