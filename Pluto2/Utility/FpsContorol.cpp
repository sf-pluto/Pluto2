#include "FpsControl.h"

namespace Utility{

FpsControl::FpsControl() : mFps( 0.0f ),
mPreviousTime( 0 ),
mCount( 0 ),
mInterval( 20 ){
}

float FpsControl::getFps(){
	return mFps;
}

void FpsControl::setInterval(int val){
	mInterval = val;
}

void FpsControl::calcFps(){
	if( ++mCount == mInterval ){
		LONGLONG now = GetNowHiPerformanceCount();
		mFps = ( mInterval * 1000000 / static_cast< float >( now - mPreviousTime ) );
		mPreviousTime = now;
		mCount = 0;
	}
}

}