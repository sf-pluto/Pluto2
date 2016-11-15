#ifndef INCLUDED_OBJECT_FIGURE_VECTOR2D_H
#define INCLUDED_OBJECT_FIGURE_VECTOR2D_H

namespace Object{

class Point2D;

class Vector2D{
public:
	Vector2D();
	Vector2D( float x , float y );
	Vector2D( const Point2D& other );
	Vector2D( const Vector2D& other );
	~Vector2D();

	const Vector2D& operator =( const Vector2D& other ){
		mX = other.mX;
		mY = other.mY;
		return (*this);
	}
	bool operator ==( const Vector2D& other ){
		return ( mX == other.mX && mY == other.mY ) ? true : false;
	}
	bool operator !=( const Vector2D& other ){
		return !( *this == other );
	}
	friend Vector2D operator +( const Vector2D& lhs , const Vector2D& rhs ){
		return Vector2D( lhs.mX + rhs.mX , lhs.mY + rhs.mY );
	}
	friend Vector2D operator -( const Vector2D& lhs , const Vector2D& rhs ){
		return Vector2D( lhs.mX - rhs.mX , lhs.mY - rhs.mY );
	}
	Vector2D operator *( float n ){
		return Vector2D( mX * n , mY * n );
	}
	Vector2D operator /( float n ){
		return Vector2D( mX / n , mY / n );
	}
	const Vector2D& operator +=( const Vector2D& other ){
		mX += other.mX;
		mY += other.mY;
		return (*this);
	}
	const Vector2D& operator -=( const Vector2D& other ){
		mX -= other.mX;
		mY -= other.mY;
		return (*this);
	}
	const Vector2D& operator /=( float n ){
		mX /= n;
		mY /= n;
		return (*this);
	}

	float getX() const;
	float getY() const;
	float getLength() const;
	float getPowLength() const;
	void normalize();
private:
	float mX;
	float mY;
};

}

float Vec2Dot( const Object::Vector2D& lhs ,  const  Object::Vector2D& rhs );

#endif //#ifndef INCLUDED_OBJECT_FIGURE_VECTOR2D_H