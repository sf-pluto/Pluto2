#ifndef INCLUDED_LIBFUNC_H
#define INCLUDED_LIBFUNC_H

#include <tchar.h>

namespace MyLib{

	void halt( const char* filename, int line, const char* message );
	void charToWChar( const char* str , wchar_t* wStrW , size_t wLen );
	void showMessageBox( const char* str );
	void outputDebug( const char* str );
}

#endif //#ifndef INCLUDED_LIBFUNC_H