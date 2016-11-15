#ifndef INCLUDED_OBJECT_FIGURE_BASE_H
#define INCLUDED_OBJECT_FIGURE_BASE_H

namespace Object{

class Figure{
public:
	enum F_TYPE{
		F_CIRCLE = 0,
		F_LINE,
		F_RECTANGLE,
		F_ROTATED_RECT,

		F_UNKNOWN,
	};
	Figure() : mColor( 0 ) , mId( F_UNKNOWN ){}
	virtual ~Figure(){}

	virtual void draw(){}
	bool isHit( Figure& other );
	F_TYPE id() const;
	void setColor( int num );
	virtual void move( float x , float y ){}
	virtual void moveTo( float x , float y ){}
protected:
	int mColor;
	F_TYPE mId;
};

}

#endif //#ifndef INCLUDED_OBJECT_FIGURE_BASE_H