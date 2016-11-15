#ifndef INCLUDED_OBJECT_FIGURE_CIRCLE_H
#define INCLUDED_OBJECT_FIGURE_CIRCLE_H

#include "base.h"
#include <boost/shared_ptr.hpp>

namespace Object{

class Point2D;

class Circle : public Figure{
public:
	Circle( const Circle& other ); 
	Circle( const Point2D& center , float radius ); 
	Circle( float x , float y , float radius ); 
	Circle( const boost::shared_ptr< Point2D >& center , float radius ); 
	~Circle();

	void draw();
	void setFilled( int flag );
	void move( float x , float y );
	void moveTo( float x , float y );
	Point2D& getCenter();
	float getRadius();
private:
	boost::shared_ptr< Point2D > mCenter;
	float mRadius;
	int mIsFilled;
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_CIRCLE_H