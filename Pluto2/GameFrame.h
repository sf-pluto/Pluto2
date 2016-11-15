#ifndef INCLUDED_GAMEFRAME_H
#define INCLUDED_GAMEFRAME_H

#include <string>

namespace Input{

class Keyboard;

}

// �Q�[���̘g�g��
class GameFrame{
public:
	GameFrame();
	~GameFrame();

	// �Q�[���̃��C�����[�v
	void doGameLoop( int WindowModeFlag );
	void createScene( const std::string& filename );
private:
	Input::Keyboard *mKeyInput;

};

#endif //#ifndef INCLUDED_GAMEFRAME_H