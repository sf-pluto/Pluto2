#include "Rectangle.h"
#include "Vector2D.h"
#include "Point2D.h"
#include "DxLib.h"

namespace Object{

Rectangle::Rectangle(const Object::Rectangle &other) : mLeft( new Point2D( other.mLeft->getX() , other.mLeft->getY() ) ),
mRight( new Point2D( other.mRight->getX() , other.mRight->getY() ) ),
mVect( other.mVect ),
mIsFilled( other.mIsFilled ){
	mId = F_RECTANGLE;
}

Rectangle::Rectangle(const Object::Point2D &left, const Object::Point2D &right) : mLeft( new Point2D( left ) ),
mRight( new Point2D( right ) ),
mVect( new Vector2D( ( *mRight - *mLeft ) / 2 ) ),
mIsFilled( FALSE ){
	mId = F_RECTANGLE;
}

Rectangle::Rectangle(float x1, float y1, float x2, float y2) : mLeft( new Point2D( x1 , y1 ) ),
mRight( new Point2D( x2 , y2 ) ),
mVect( new Vector2D( x2 - x1 , y2 - y1 ) ),
mIsFilled( FALSE ){
	mId = F_RECTANGLE;
}

Rectangle::Rectangle(const Object::Point2D &left, float width, float height) : mLeft( new Point2D( left ) ),
mRight( new Point2D( mLeft->getX() + width , mLeft->getY() + height ) ),
mVect( new Vector2D( width / 2 , height / 2 ) ),
mIsFilled( FALSE ){
	mId = F_RECTANGLE;
}

Rectangle::Rectangle(const boost::shared_ptr< Point2D >& left, const boost::shared_ptr< Point2D >& right) :
mLeft( left ),
mRight( right ),
mIsFilled( FALSE ){
	mId = F_RECTANGLE;
}

Rectangle::~Rectangle(){
}

void Rectangle::draw(){
	DrawBox( mLeft->getXToInt() , mLeft->getYToInt() , mRight->getXToInt() , mRight->getYToInt() , mColor , mIsFilled );
}

void Rectangle::move(float x, float y){
	mLeft->add( x , y );
	mRight->add( x , y );
}

void Rectangle::moveTo(float x, float y){
	x -= mLeft->getX();
	y -= mLeft->getY();
	mLeft->add( x , y );
	mRight->add( x , y );
}

void Rectangle::setFilled(int flag){
	mIsFilled = flag;
}

Vector2D& Rectangle::getVector(){
	return *mVect;
}

Point2D& Rectangle::getLeftTop(){
	return *mLeft;
}

Point2D& Rectangle::getRightBottom(){
	return *mRight;
}

Point2D Rectangle::getLeftBottom(){
	return Point2D( mLeft->getX() , mRight->getY() );
}

Point2D Rectangle::getRightTop(){
	return Point2D( mRight->getX() , mLeft->getY() );
}

}