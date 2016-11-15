#include "File.h"
#include "DxLib.h"

namespace Object{

File::File(const char* path) : mHandle( FileRead_open( path ) ),
mSize( FileRead_size( path ) ){
}

File::~File(){
	FileRead_close( mHandle );
}

std::string File::readAll(){
	void* buf = malloc( mSize );
	FileRead_read( buf , mSize , mHandle );
	std::string s( static_cast< char* >( buf ) );
	free( buf );
	return s;
}

}