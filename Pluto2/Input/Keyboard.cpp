#include "Keyboard.h"
#include "DxLib.h"

namespace Input{

void Keyboard::getAllKeyState(){
	GetHitKeyStateAll( mBuf ) ;
}
bool Keyboard::isKeyPressed( int num ){
	return mBuf[ num ] == 1;
}
char Keyboard::mBuf[ 256 ];

}; // namespace Input