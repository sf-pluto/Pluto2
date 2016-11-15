#ifndef INCLUDED_OBJECT_IMAGE_H
#define INCLUDED_OBJECT_IMAGE_H

namespace Object{

class Image{
public:
	Image();
	Image( int handle );
	Image( const char *name );
	Image( const Image& other );
	Image( const Image& other, int x1, int y1, int x2, int y2 );
	
	~Image();

	void draw( int x , int y ) const;
	void drawF( float x , float y ) const;
	void drawCenter( int x , int y ) const;
	void drawCenterF( float x , float y ) const;
	void drawRect( int x , int y , int srcx , int srcy , int width , int height ) const;
	void drawRectF( float x , float y , int srcx , int srcy , int width , int height ) const;
	void drawModi( int x , int y , float ratex , float ratey ) const;
	void drawModiF( float x , float y , float ratex , float ratey ) const;
	void drawRotate( int x , int y , float rad ) const; 

	bool isOutOfWindowF( float x , float y ) const; 
	Image derive( int x , int y , int width, int height );

	int handle();
	int handle() const;

private:
	int mImageHandle;
	int mImageSizeX;
	int mImageSizeY;

private:
	const char* mFilename;
};

}

#endif //#ifndef INCLUDED_OBJECT_IMAGE_H