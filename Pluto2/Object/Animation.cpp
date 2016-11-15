#include "Animation.h"
#include "DxLib.h"

namespace Object{

Animation::Animation() : mImageHandle( -1 ){
}

Animation::Animation(const char *name, int inum, int numx, int numy, int sizex, int sizey) : mInterval( 1 ),
mCurrentImage( 0 ),
mCount( 0 ),
mIsReversed( false ){
	mImageHandle = LoadGraph( name );
	GetGraphSize( mImageHandle , &mImageSizeX , &mImageSizeY );
	for( int i = 0 ; i < inum ; i++ ){
		mImages.push_back( DerivationGraph( ( i % numx ) * sizex , ( i / numx ) * sizey , sizex , sizey , mImageHandle ) );
	}
	mRefarencedCount = new int( 0 );
}

Animation::Animation(int handle, const std::vector<int>& images) : mImageHandle( handle ),
mImages( images ),
mInterval( 1 ),
mCount( 0 ),
mCurrentImage( 0 ),
mRefarencedCount( new int( 0 ) ),
mIsReversed( false ){
	GetGraphSize( mImageHandle , &mImageSizeX , &mImageSizeY );
	*mRefarencedCount++;
}

Animation::Animation(const Object::Animation &other) : mImageHandle( other.mImageHandle ),
mInterval( other.mInterval ),
mCurrentImage( other.mCurrentImage ),
mCount( other.mCount ),
mRefarencedCount( other.mRefarencedCount ),
mIsReversed( other.mIsReversed ){
	*mRefarencedCount++;
}

Animation::~Animation(){
	if( *mRefarencedCount > 0 ){
		*mRefarencedCount --;
	}else{
		DeleteGraph( mImageHandle );
		delete mRefarencedCount;
	}
}

void Animation::setInterval(int num){
	mInterval = num;
}

void Animation::draw(int x, int y){
	DrawGraph( x , y , mImages.at( mCurrentImage ) , TRUE );
	if( ++mCount >= mInterval ){
		mCount = 0;
		mCurrentImage++;
	}
	if( mCurrentImage == mImages.size() ) mCurrentImage = 0;
}

void Animation::swing(int x, int y){
	DrawGraph( x , y , mImages.at( mCurrentImage ) , TRUE );
	if( ++mCount >= mInterval && mImages.size() > 1 ){
		mCount = 0;
		mCurrentImage += mIsReversed ? -1 : 1 ;
	}
	if( mCurrentImage == mImages.size() && !mIsReversed ){
		mIsReversed = true;
		mCurrentImage -= 2;
	}else if( mCurrentImage == -1 && mIsReversed ){
		mIsReversed = false;
		mCurrentImage += 2;
	}
}

}