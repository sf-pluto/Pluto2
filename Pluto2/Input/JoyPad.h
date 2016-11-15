#ifndef INCLUDED_INPUT_JOYPAD_H
#define INCLUDED_INPUT_JOYPAD_H

#include "../Class/Singleton.h"

namespace Input{

class JoyPad : public Singleton< JoyPad >{
public:
	bool isButtonInputed( int key );
	void getJoypadInput(); 
private:
	int mBuf;
};

}

#endif //#ifndef INCLUDED_INPUT_JOYPAD_H