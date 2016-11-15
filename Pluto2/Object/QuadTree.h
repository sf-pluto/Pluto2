#ifndef INCLUDED_OBJECT_QUADTREE_H
#define INCLUDED_OBJECT_QUADTREE_H

#include "../Class/Singleton.h"
#include "QuadNode.h"

namespace Object{

class QuadNode;
class Point2D;

class QuadTree : public Singleton< QuadTree >{
public:
	QuadTree();

	void setAreaSize( int width, int height );
	QuadNode getQuadNode( const Point2D& lhs, const Point2D& rhs );
private:
	int mAreaWidth, mAreaHeight;
	int mAreaX, mAreaY;
	int mDivisionNum;
	int mDivisionPart;
	float mDivisionX, mDivisionY;

	inline int convertToMorton( int x, int y );
	inline int devideBit( int n );
};

}

#endif //#ifndef INCLUDED_OBJECT_QUADTREE_H