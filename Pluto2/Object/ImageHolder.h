#ifndef INCLUDED_OBJECT_IMAGEHOLDER_H
#define INCLUDED_OBJECT_IMAGEHOLDER_H

#include "../Class/Singleton.h"
#include <map>
// unordered_map and string
using namespace std;

class ImageHolder : public Singleton< ImageHolder >{
public:
	int getImage( const char* str );
	void releaseImage( const char* str );
private:
	struct ImageData{
		ImageData( int handle );
		int mHandle;
		int mCount;
	};
	typedef map< const char* , ImageData > ImageMap;
	ImageMap mMap;
	int add( const char* str );
};

#endif //#ifndef INCLUDED_OBJECT_IMAGEHOLDER_H