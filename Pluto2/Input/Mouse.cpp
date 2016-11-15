#include "Mouse.h"
#include "../PlUtils.h"
#include "DxLib.h"
#include "../Object/Figure/Point2D.h"

namespace Input{

Mouse::Mouse() : mPos( new Object::Point2D( 0.f, 0.f ) ){
}

Mouse::~Mouse(){
	SAFE_DELETE( mPos ); 
}

void Mouse::setVisible(int flag){
	SetMouseDispFlag( flag );
}

void Mouse::getMouseInput(){
	int x = 0;
	int y = 0;
	GetMousePoint( &x , &y );
	mBuf = GetMouseInput();
	mPos->set( static_cast< float >( x ) , static_cast< float >( y ) );
}

bool Mouse::isMouseInputed(int button){
	return ( mBuf & button ) != 0 ? true : false;
}

const Object::Point2D& Mouse::getMousePosition(){
	return *mPos;
}

}