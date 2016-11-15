#ifndef INCLUDED_OBJECT_FONT_H
#define INCLUDED_OBJECT_FONT_H

#include <boost/utility.hpp>

namespace Object{

class Font : public boost::noncopyable{
public:
	Font( const char* name , int size , int thinck , int type );
	~Font();

	void draw( int x , int y , const char* str , int color );
private:
	int mFontHandle;
};

}

#endif //#ifndef INCLUDED_OBJECT_FONT_H