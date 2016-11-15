#ifndef INCLUDED_OBJECT_FIGURE_POINT2D_H
#define INCLUDED_OBJECT_FIGURE_POINT2D_H

#include <cmath>

namespace Object{

class Point2D{
public:
	Point2D() : mX(),
		mY(){}
	Point2D( float x , float y ) : mX( x ),
		mY( y ){}
	Point2D( const Point2D& other ) : mX( other.mX ),
		mY( other.mY ){}
	~Point2D(){}
	float getX() const;
	float getY() const;
	int getXToInt() const;
	int getYToInt() const;
	float getLength() const;
	float getPowLength() const;
	void add( float x , float y );
	void set( float x , float y );
	
	const Point2D& operator =( const Point2D& other ){
		mX = other.mX;
		mY = other.mY;
		return (*this);
	}
	bool operator ==( const Point2D& other ){
		return ( mX == other.mX && mY == other.mY ) ? true : false;
	}
	bool operator !=( const Point2D& other ){
		return !( *this == other );
	}
	friend Point2D operator +( const Point2D& lhs , const Point2D& rhs ){
		return Point2D( lhs.mX + rhs.mX , lhs.mY + rhs.mY );
	}
	friend Point2D operator -( const Point2D& lhs , const Point2D& rhs ){
		return Point2D( lhs.mX - rhs.mX , lhs.mY - rhs.mY );
	}
	Point2D operator *( float n ){
		return Point2D( mX * n , mY * n );
	}
	Point2D operator /( float n ){
		return Point2D( mX / n , mY / n );
	}
	const Point2D& operator +=( const Point2D& other ){
		mX += other.mX;
		mY += other.mY;
		return (*this);
	}
	const Point2D& operator -=( const Point2D& other ){
		mX -= other.mX;
		mY -= other.mY;
		return (*this);
	}

private:
	float mX;
	float mY;
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_POINT2D_H