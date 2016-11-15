#ifndef INCLUDED_UTILITY_WINDOWMANAGER_H
#define INCLUDED_UTILITY_WINDOWMANAGER_H

#include "../Class/Singleton.h"

namespace Utility{

class WindowManager : public Singleton< WindowManager >{
public:
	WindowManager();

	int getWindowX();
	int getWindowY();
private:
	int mX;
	int mY;
};

}

#endif //#ifndef INCLUDED_UTILITY_WINDOWMANAGER_H