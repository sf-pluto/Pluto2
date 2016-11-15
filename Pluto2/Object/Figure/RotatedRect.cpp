#include "RotatedRect.h"
#include "Point2D.h"

namespace Object{

RotatedRect::RotatedRect(const Object::RotatedRect &other) : mCenter( new Point2D( other.mCenter->getX() , other.mCenter->getY() ) ),
mWidth( other.mWidth ),
mHeight( other.mHeight ),
mAngle( other.mAngle ){
	mId = F_ROTATED_RECT;
}

RotatedRect::RotatedRect(const Object::Point2D &center, float width, float height, float angle) : mCenter( new Point2D( center ) ),
mWidth( width ),
mHeight( height ),
mAngle( angle ){
	mId = F_ROTATED_RECT;
}

RotatedRect::RotatedRect(const boost::shared_ptr< Point2D > &center, float width, float height, float angle) : mCenter( center ),
mWidth( width ),
mHeight( height ),
mAngle( angle ){
	mId = F_ROTATED_RECT;
}

RotatedRect::RotatedRect(float cx, float cy, float width, float height, float angle) : mCenter( new Point2D( cx , cy ) ),
mWidth( width ),
mHeight( height ),
mAngle( angle ){
	mId = F_ROTATED_RECT;
}

RotatedRect::~RotatedRect(){
}

void RotatedRect::draw(){
}

void RotatedRect::move(float x, float y){
	mCenter->add( x , y );
}

void RotatedRect::moveTo(float x, float y){
	mCenter->set( x , y );
}

float RotatedRect::height(){
	return mHeight;
}

float RotatedRect::width(){
	return mWidth;
}

float RotatedRect::angle(){
	return mAngle;
}

Point2D& RotatedRect::getCenter(){
	return *mCenter;
}

}