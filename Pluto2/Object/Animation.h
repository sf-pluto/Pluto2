#ifndef INCLUDED_OBJECT_ANIMATION_H
#define INCLUDED_OBJECT_ANIMATION_H

#include <vector>

using namespace std;

namespace Object{

class Animation{
public:
	Animation();
	Animation( int handle , const vector< int >& images );
	Animation( const char *name , int inum , int numx , int numy , int sizex , int sizey );
	Animation( const Animation& other );
	~Animation();

	void setInterval( int val );
	void draw( int x , int y );
	void swing( int x , int y );
	
protected:
	int mImageHandle;
	vector< int > mImages;

private:
	int* mRefarencedCount;
	int mCurrentImage;
	int mInterval;
	int mCount;
	int mImageSizeX;
	int mImageSizeY;
	bool mIsReversed;
};

}

#endif //#ifndef INCLUDED_OBJECT_ANIMATION_H