#ifndef INCLUDED_GAMEFRAME_H
#define INCLUDED_GAMEFRAME_H

#include <string>

namespace Input{

class Keyboard;

}

// ゲームの枠組み
class GameFrame{
public:
	GameFrame();
	~GameFrame();

	// ゲームのメインループ
	void doGameLoop( int WindowModeFlag );
	void createScene( const std::string& filename );
private:
	Input::Keyboard *mKeyInput;

};

#endif //#ifndef INCLUDED_GAMEFRAME_H