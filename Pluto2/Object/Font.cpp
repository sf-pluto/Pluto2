#include "Font.h"
#include "DxLib.h"

namespace Object{

Font::Font(const char *name, int size, int thinck, int type) : mFontHandle( CreateFontToHandle( name , size , thinck , type ) ){
}

Font::~Font(){
	DeleteFontToHandle( mFontHandle );
}

void Font::draw(int x, int y, const char *str, int color){
	DrawStringToHandle( x , y , str , color , mFontHandle );
}

}