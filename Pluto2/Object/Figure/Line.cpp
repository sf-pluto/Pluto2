#include "Line.h"
#include "Point2D.h"
#include "DxLib.h"

namespace Object{

Line::Line(const Object::Point2D &left, const Object::Point2D &right) : mLeft( new Point2D( left ) ),
mRight( new Point2D( right ) ){
}

Line::Line(const boost::shared_ptr< Point2D >& left, const boost::shared_ptr< Point2D >& right) :
mLeft( left ),
mRight( right ){
}

Line::~Line(){
}

void Line::draw(){
	DrawLine( mLeft->getXToInt() , mLeft->getYToInt() , mRight->getXToInt() , mRight->getYToInt() , mColor );
}

}