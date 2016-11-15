#ifndef INCLUDED_OBJECT_FIGURE_RECTANGLE_H
#define INCLUDED_OBJECT_FIGURE_RECTANGLE_H

#include "base.h"
#include <boost/shared_ptr.hpp>

namespace Object{

class Point2D;
class Vector2D;

class Rectangle : public Figure{
public:
	Rectangle( const Rectangle& other );
	Rectangle( const Point2D& left , const Point2D& right );
	Rectangle( const Point2D& left , float width , float height );
	Rectangle( float x1 , float y1 , float x2 , float y2 );
	Rectangle( const boost::shared_ptr< Point2D >& left , const boost::shared_ptr< Point2D >& right );
	~Rectangle();

	void draw();
	void move( float x , float y );
	void moveTo( float x , float y );
	void setFilled( int flag );
	Vector2D& getVector();
	Point2D& getLeftTop();
	Point2D& getRightBottom();
	Point2D getLeftBottom();
	Point2D getRightTop();
private:
	boost::shared_ptr< Point2D > mLeft;
	boost::shared_ptr< Point2D > mRight;
	boost::shared_ptr< Vector2D > mVect;
	int mIsFilled; 
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_RECTANGLE_H