#include "libFunc.h"

#include <crtdbg.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h>


namespace MyLib{
#ifndef NDEBUG
	void halt( const char* filename, int line, const char* message ){
		/*size_t wFileNameLen = strlen(filename);
		wchar_t* wFileName = new wchar_t[ wFileNameLen + 1 ];
		charToWChar( filename , &wFileName[ 0 ], wFileNameLen );
		size_t wMessageLen = strlen(message);
		wchar_t* wMessage = new wchar_t[ wMessageLen + 1 ];
		charToWChar( message , &wMessage[ 0 ], wMessageLen);*/
		_CrtDbgReport( _CRT_ASSERT , filename , line , message , NULL );
		/*delete wFileName;
		delete wMessage;*/
	}

	void charToWChar(const char *str, wchar_t* wStrW, size_t wLen){
		setlocale( LC_ALL , "japanese" );
		mbstowcs_s(&wLen , wStrW , wLen + 1 , str , _TRUNCATE);

	}

	void showMessageBox( const char* str ){
		MessageBoxEx( NULL , str , "ÉGÉâÅ[" , MB_OK , LANG_JAPANESE );
	}

	/*void outputDebug( const char* str ){
		OutputDebugStr( str );
	}*/
#endif
}