#ifndef INCLUDED_INPUT_MOUSE_H
#define INCLUDED_INPUT_MOUSE_H

#include "../Class/Singleton.h"

namespace Object{
	class Point2D;
}

namespace Input{

class Mouse : public Singleton< Mouse >{
public:
	Mouse();
	~Mouse();

	bool isMouseInputed( int button );
	const Object::Point2D& getMousePosition();
	void setVisible( int flag );
	void getMouseInput();
private:
	int mBuf;
	Object::Point2D* mPos;
};

}

#endif //#ifndef INCLUDED_INPUT_MOUSE_H