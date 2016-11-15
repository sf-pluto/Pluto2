#ifndef INCLUDED_UTILITY_FPSCONTROL_H
#define INCLUDED_UTILITY_FPSCONTROL_H

#include "../class/Singleton.h"
#include "DxLib.h"

namespace Utility{

class FpsControl : public Singleton< FpsControl >{
public:
	FpsControl();

	float getFps();
	void setInterval( int val );
	void calcFps();
private:
	int mInterval;
	int mCount;
	float mFps;
	LONGLONG mPreviousTime;
};

}

#endif //#ifndef INCLUDED_UTILITY_FPSCONTROL_H