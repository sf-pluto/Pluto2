#ifndef INCLUDED_INPUT_KEYBOARD_H
#define INCLUDED_INPUT_KEYBOARD_H

namespace Input{

class Keyboard{
public:
	static char mBuf[];
	static void getAllKeyState();
	static bool isKeyPressed( int num );
};

}; // namespace Input

#endif //#ifndef INCLUDED_INPUT_KEYBOARD_H