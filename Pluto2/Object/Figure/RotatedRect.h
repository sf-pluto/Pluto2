#ifndef INCLUDED_OBJECT_FIGURE_ROTATEDRECT_H
#define INCLUDED_OBJECT_FIGURE_ROTATEDRECT_H

#include "base.h"
#include <boost/shared_ptr.hpp>

namespace Object{

class Point2D;
class Vector2D;

class RotatedRect : public Figure{
public:
	RotatedRect( const RotatedRect& other );
	RotatedRect( const Point2D& center , float width , float height , float angle );
	RotatedRect( const boost::shared_ptr< Point2D >& center , float width , float height , float angle );
	RotatedRect( float cx , float cy , float width , float height , float angle );
	~RotatedRect();

	void draw();
	void move( float x , float y );
	void moveTo( float x , float y );
	float width();
	float height();
	float angle();
	Point2D& getCenter();
private:
	boost::shared_ptr< Point2D > mCenter;
	float mWidth;
	float mHeight;
	float mAngle;
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_ROTATEDRECT_H