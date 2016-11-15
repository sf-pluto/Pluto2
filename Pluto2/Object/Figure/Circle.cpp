#include "Circle.h"
#include "Point2D.h"
#include "DxLib.h"
#include <boost/cast.hpp>


namespace Object{

Circle::Circle(const Object::Circle &other) : mCenter( new Point2D( other.mCenter->getX() , other.mCenter->getY() ) ),
mRadius( other.mRadius ),
mIsFilled( other.mIsFilled ){
	mId = F_CIRCLE;
}

Circle::Circle(const Object::Point2D &center, float radius) : mCenter( new Point2D( center ) ),
mRadius( radius ),
mIsFilled( FALSE ){
	mId = F_CIRCLE;
}

Circle::Circle(float x, float y, float radius) : mCenter( new Point2D( x , y ) ),
mRadius( radius ),
mIsFilled( FALSE ){
	mId = F_CIRCLE;
}

Circle::Circle(const boost::shared_ptr<Point2D> &center, float radius) : mCenter( center ),
mRadius( radius ),
mIsFilled( FALSE ){
	mId = F_CIRCLE;
}

Circle::~Circle(){
}

void Circle::draw(){
	DrawCircle( mCenter->getXToInt() , mCenter->getYToInt() , static_cast< int >( mRadius ) , mColor , mIsFilled );
}

void Circle::setFilled(int flag){
	mIsFilled = flag;
}

void Circle::move(float x, float y){
	mCenter->add( x , y ); 
}

void Circle::moveTo(float x, float y){
	mCenter->set( x , y ); 
}

Point2D& Circle::getCenter(){
	return *mCenter;
}

float Circle::getRadius(){
	return mRadius;
}

}