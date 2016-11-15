#include "ImageHolder.h"
#include "DxLib.h"

int ImageHolder::getImage(const char *str){
	ImageMap::iterator it = mMap.find( str );
	if( it == mMap.end() ){
		return add( str );
	}else{
		++ (*it).second.mCount;
		return (*it).second.mHandle;
	}
}

int ImageHolder::add(const char *str){
	int handle = LoadGraph( str );
	mMap.insert( make_pair( str , ImageData( handle ) ) );
	return handle;
}

void ImageHolder::releaseImage(const char *str){
	ImageMap::iterator it = mMap.find( str );
	if( it == mMap.end() ){
		// ‰æ‘œ‚ª‘¶İ‚µ‚È‚¢
	}else if( --(*it).second.mCount <= 0 ){
		DeleteGraph( (*it).second.mHandle ); 
		mMap.erase( it );
	}
}

ImageHolder::ImageData::ImageData(int handle) : mHandle( handle ) ,
mCount( 1 ){
}