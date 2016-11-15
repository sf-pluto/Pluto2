#include "QuadTree.h"
#include "Figure/Point2D.h"
#include "../Utility/WindowManager.h"

namespace Object{

QuadTree::QuadTree() : mAreaWidth( Utility::WindowManager::instance()->getWindowX() ),
mAreaHeight( Utility::WindowManager::instance()->getWindowY() ),
mAreaX( 0 ),
mAreaY( 0 ),
mDivisionNum( 3 ),
mDivisionPart( 8 ),
mDivisionX( static_cast< float >( mAreaWidth ) / mDivisionPart ),
mDivisionY( static_cast< float >( mAreaHeight ) / mDivisionPart ){
}

void QuadTree::setAreaSize(int width, int height){
	mAreaWidth = width;
	mAreaHeight = height;
}

Object::QuadNode QuadTree::getQuadNode(const Point2D& lhs, const Point2D& rhs){
	// value check
	int x1 = static_cast< int >( lhs.getX() / mDivisionX );
	int y1 = static_cast< int >( lhs.getY() / mDivisionY );
	int x2 = static_cast< int >( rhs.getX() / mDivisionX );
	int y2 = static_cast< int >( rhs.getY() / mDivisionY );
	int n1 = convertToMorton( x1, y1 );
	int n2 = convertToMorton( x2, y2 );
	int n3 = n1 ^ n2;
	int level = 0;
	for( int i = 1; i <= mDivisionNum; i++ ){
		if( n3 & 0x00000003 != 0 ) level = i;
		n3 >>= 2;
	}
	return QuadNode( n1, level ); 
}

int QuadTree::convertToMorton(int x, int y){
	return ( devideBit(x) | ( devideBit(y) << 1 ) );
}

int QuadTree::devideBit(int n){
	n = ( n | ( n << 8 ) ) & 0x00ff00ff;
	n = ( n | ( n << 4 ) ) & 0x0f0f0f0f;
	n = ( n | ( n << 2 ) ) & 0x33333333;
	return ( n | ( n << 1 ) ) & 0x55555555;
}

}