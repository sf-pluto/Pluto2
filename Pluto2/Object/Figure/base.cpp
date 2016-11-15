#include "base.h"
#include "HitChecker.h"

namespace Object{

void Figure::setColor( int num ){
	mColor = num;
}

Figure::F_TYPE Figure::id() const{ 
	return mId;
}

bool Figure::isHit(Object::Figure &other){
	return HitCheck::doHitCheck( *this , other );
}

}