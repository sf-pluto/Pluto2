#include "Point2D.h"

namespace Object{

float Point2D::getX() const{
	return mX;
}

float Point2D::getY() const{
	return mY;
}

int Point2D::getXToInt() const{
	return static_cast< int >( mX );
}

int Point2D::getYToInt() const{
	return static_cast< int >( mY );
}

float Point2D::getLength() const{
	return sqrt( mX * mX + mY * mY );
}

float Point2D::getPowLength() const{
	return mX * mX + mY * mY;
}

void Point2D::add(float x, float y){
	mX += x;
	mY += y;
}

void Point2D::set(float x, float y){
	mX = x;
	mY = y;
}

}