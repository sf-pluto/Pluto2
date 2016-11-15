#include "GameObjectGroup.h" 
#include "GameObject.h"
#include "../PlUtils.h"
#include "../Lua/LuaUtils.h"
#include "../Lua/LuaCurrentState.h"
#include <boost/make_shared.hpp>

namespace Object{

GameObjectGroup::GameObjectGroup(){
}

GameObjectGroup::~GameObjectGroup(){
}

void GameObjectGroup::createObject(const Object::Image &image, float x, float y, float a, float s){
	mObjectList.push_back( ObjPtr( new GameObject( image , x , y , a , s ) ) );
}

void GameObjectGroup::addObject(const Object::GameObject &ref){
	mObjectList.push_back( ObjPtr( new GameObject( ref ) ) );
}

void GameObjectGroup::setFunction(const std::string &str){
	mFunction = str;
	//mUsingRef = false;
}

void GameObjectGroup::setAction(const std::string &str){
	mObjectList.back()->setAction( str );
}

void GameObjectGroup::setHP(int val){
	mObjectList.back()->setHP( val );
}

void GameObjectGroup::setVisible(bool val){
	mObjectList.back()->setVisible( val );
}

//void GameObjectGroup::setFunction(luabind::adl::object* obj){
//	mObjectRef = obj;
//	mUsingRef = true;
//}

void GameObjectGroup::doFunction(){
	list< ObjPtr >::iterator it = mObjectList.begin();
	if( mFunction.empty() ) return;
	while( it != mObjectList.end() ){
		/*if( mUsingRef ){
			luabind::call_function< void >( *mObjectRef , (*it) );
		}else{*/
			luabind::call_function< void >( LuaCurrentState::instance()->getState() , mFunction.c_str() , (*it) );
		//}
		if( (*it)->isDead() ){
			//(*it)->~GameObject();
			it = mObjectList.erase( it );
		}else{
			it++;
		}
	}
}

void GameObjectGroup::addHitArea(Object::Figure *area){
	mObjectList.back()->addHitArea( area );
}

int GameObjectGroup::count(){
	return mObjectList.size();
}

const std::list< GameObjectGroup::ObjPtr >& GameObjectGroup::getObjectList() const{
	return mObjectList;
}

}