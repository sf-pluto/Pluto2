#ifndef INCLUDED_OBJECT_FILE_H
#define INCLUDED_OBJECT_FILE_H

#include <string>

namespace Object{

class File{
public:
	File( const char* path );
	~File();

	std::string readAll();
private:
	int mHandle;
	int mSize;
};

}

#endif //#ifndef INCLUDED_OBJECT_FILE_H