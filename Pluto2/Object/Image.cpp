#include "DxLib.h"

#include "Image.h"
#include "ImageHolder.h"
#include "../Utility/WindowManager.h"

namespace Object{

Image::Image() : mImageHandle( -1 ){
}

Image::Image(const char *name) : mFilename( name ){
	mImageHandle = ImageHolder::instance()->getImage( name );
	GetGraphSize( mImageHandle , &mImageSizeX , &mImageSizeY );
}

Image::Image(int handle) : mImageHandle( handle ){
	GetGraphSize( mImageHandle , &mImageSizeX , &mImageSizeY );
}

Image::Image(const Image &other) : mFilename( other.mFilename ),
mImageHandle(  ImageHolder::instance()->getImage( mFilename ) ),
mImageSizeX( other.mImageSizeX ),
mImageSizeY( other.mImageSizeY )
{
}

Image::Image(const Object::Image &other, int x1, int y1, int x2, int y2) : mFilename( other.mFilename ),
mImageHandle( DerivationGraph( x1, y1, x2, y2, other.mImageHandle ) ),
mImageSizeX( x2 ),
mImageSizeY( y2 ){
}

Image::~Image(){
	ImageHolder::instance()->releaseImage( mFilename );
}

void Image::draw(int x, int y) const{
	DrawGraph( x , y , mImageHandle , TRUE );
}
void Image::drawF(float x, float y) const{
	draw( static_cast< int >( x ) , static_cast< int >( y ) );
}

void Image::drawCenter(int x, int y) const{
	DrawGraph( x - mImageSizeX / 2 , y - mImageSizeY / 2 , mImageHandle , TRUE );
}
void Image::drawCenterF(float x, float y) const{
	drawCenter( static_cast< int >( x ) , static_cast< int >( y ) );
}

void Image::drawRect(int x, int y, int srcx, int srcy, int width, int height) const{
	DrawRectGraph( x , y , srcx , srcy , width , height , mImageHandle , TRUE , FALSE );
}
void Image::drawRectF(float x, float y, int srcx, int srcy, int width, int height) const{
	drawRect( static_cast< int >( x ) , static_cast< int >( y ) , srcx , srcy , width , height );
}

void Image::drawModi(int x, int y, float ratex, float ratey) const{
	int x1 = x - static_cast< int >( ratex * mImageSizeX ) / 2;
	int x2 = x + static_cast< int >( ratex * mImageSizeX + 1 ) / 2;
	int y1 = y - static_cast< int >( ratey * mImageSizeY ) / 2;
	int y2 = y + static_cast< int >( ratey * mImageSizeY ) / 2 + 1;
	DrawModiGraph( x1 ,  y1 , x2 , y1 , x2 , y2 , x1 , y2 , mImageHandle , TRUE ); 
}
void Image::drawModiF(float x, float y, float ratex, float ratey) const{
	drawModi( static_cast< int >( x ) , static_cast< int >( y ) , ratex , ratey );
}

void Image::drawRotate(int x, int y, float rad) const{
	DrawRotaGraph( x , y , 1.0 , rad , mImageHandle , TRUE );
}

bool Image::isOutOfWindowF(float x, float y) const{
	int wx = Utility::WindowManager::instance()->getWindowX();
	int wy = Utility::WindowManager::instance()->getWindowY();
	if( x - mImageSizeX / 2 > wx ) return true;
	if( x + mImageSizeX / 2 < 0 ) return true;
	if( y - mImageSizeY / 2 > wy ) return true;
	if( y + mImageSizeY / 2 < 0 ) return true;
	return false;
}

Image Image::derive(int x, int y, int width, int height){
	int buf = DerivationGraph(x, y, width, height, mImageHandle);
	Image img = Image(buf);
	return img;
}

int Image::handle(){
	return mImageHandle;
}

int Image::handle() const{
	return mImageHandle;
}

}