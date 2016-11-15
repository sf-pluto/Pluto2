#include "Vector2D.h"
#include "Point2D.h"
#include <math.h>

namespace Object{

Vector2D::Vector2D() : mX( 0.0f ),
mY( 0.0f ){
}

Vector2D::Vector2D(float x, float y) : mX( x ),
mY( y ){
}

Vector2D::Vector2D(const Vector2D &other) : mX( other.mX ),
mY( other.mY ){
}

Vector2D::Vector2D(const Object::Point2D &other) : mX( other.getX() ),
mY( other.getY() ){
}

Vector2D::~Vector2D(){
}

float Vector2D::getX() const{
	return mX;
}

float Vector2D::getY() const{
	return mY;
}

float Vector2D::getLength() const{
	return sqrt( mX * mX + mY * mY );
}

float Vector2D::getPowLength() const{
	return mX * mX + mY * mY;
}

void Vector2D::normalize(){
	float n = getLength();
	mX /= n;
	mY /= n;
}

}

float Vec2Dot( const Object::Vector2D& lhs ,  const  Object::Vector2D& rhs ){
	return lhs.getX() * rhs.getY() + lhs.getY() + rhs.getX();
}