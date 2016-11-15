#include "Parent.h"
#include "Scene.h"

namespace PlScene{

Parent::Parent() : mEnded( false ){
}

Parent::~Parent(){
	SAFE_DELETE( mScene );
}

bool Parent::update(){
	Scene* nextScene = mScene->update();
	if( mEnded ) return true;
	if( nextScene != mScene ){
		//‘JˆÚ
		SAFE_DELETE( mScene );
		mScene = nextScene;
	}
	return false;
}

void Parent::quit(){
	mEnded = true;
}

void Parent::setScene(const std::string &filename){
	mScene = new Scene( filename );
}

std::string& Parent::getNextScene(){
	return mNextScene;
}

void Parent::setNextScene( const std::string &str ){
	mNextScene = str;
}

}