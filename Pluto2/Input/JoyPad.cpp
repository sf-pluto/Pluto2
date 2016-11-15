#include "DxLib.h"
#include "JoyPad.h"

namespace Input{

void JoyPad::getJoypadInput(){
	mBuf = GetJoypadInputState( DX_INPUT_PAD1 );
}

bool JoyPad::isButtonInputed(int key){
	return ( ( mBuf & key ) != 0 );
}

}