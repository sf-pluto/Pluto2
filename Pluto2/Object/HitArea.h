#ifndef INCLUDED_OBJECT_HITAREA_H
#define INCLUDED_OBJECT_HITAREA_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include "QuadNode.h"

using namespace std;

namespace Object{

class Figure;
class Circle;
class Point2D;
class RotatedRect;
class QuadTree;

class HitArea{
public:
	HitArea();
	HitArea( const HitArea& other );
	~HitArea();

	void addArea( Figure* ptr );
	void addCircle( float x , float y , float r );
	void addRectangle( float x1 , float y1 , float x2 , float y2 );
	void addRotatedRect( float cx , float cy , float width , float height , float angle );
	void move( float x , float y );
	void moveTo( float x , float y );
	void destroy();
	void draw();
	bool isHit( HitArea& other );
	bool isHit( Figure& other );
private:
	typedef boost::shared_ptr< Figure > FigPtr;
	typedef boost::shared_ptr< Point2D > Pt2Ptr;
	vector< FigPtr > mVector;

	Pt2Ptr mAreaTop;
	Pt2Ptr mAreaBottom;
	QuadNode mAreaNum;
	QuadTree* mQuadTree;
	bool mAreaInitalized;

	void setAreaPos( float x1, float y1, float x2, float y2 );
};

}

#endif //#ifndef INCLUDED_OBJECT_HITAREA_H