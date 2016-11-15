#ifndef INCLUDED_OBJECT_FIGURE_LINE_H
#define INCLUDED_OBJECT_FIGURE_LINE_H

#include "base.h"
#include <boost/shared_ptr.hpp>

namespace Object{

class Point2D;

class Line : public Figure{
public:
	Line( const Point2D& left , const Point2D& right ); 
	Line( const boost::shared_ptr< Point2D >& left , const boost::shared_ptr< Point2D >& right ); 
	~Line();

	void draw();
private:
	boost::shared_ptr< Point2D > mLeft;
	boost::shared_ptr< Point2D > mRight;
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_LINE_H