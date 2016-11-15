#ifndef INCLUDED_OBJECT_ACTION_H
#define INCLUDED_OBJECT_ACTION_H

namespace Object{

class Action{
public:
	Action();
	~Action();

	enum COMMAND{
	};
private:
	struct ActionData{
		int frame;
		COMMAND command;
	}
};

}

#endif //#ifndef INCLUDED_OBJECT_ACTION_H