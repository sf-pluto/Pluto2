#include "WindowManager.h"
#include "DxLib.h"

namespace Utility{

WindowManager::WindowManager(){
	GetWindowSize( &mX, &mY );
}

int WindowManager::getWindowX(){
	return mX;
}

int WindowManager::getWindowY(){
	return mY;
}
}