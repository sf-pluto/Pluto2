#ifndef INCLUDED_PLUTILS_H
#define INCLUDED_PLUTILS_H

#include <crtdbg.h>
#include "libFunc.h"
#include <boost/foreach.hpp>

#define SAFE_DELETE( x ){\
	delete( x );\
	( x ) = 0;\
}
#define SAFE_DELETE_ARRAY( x ){\
	delete[]( x );\
	( x ) = 0;\
}
#define foreach BOOST_FOREACH

#ifndef NDEBUG
#define ASSERT( x ) _ASSERT( x );
#define HALT( exp ) { MyLib::halt( __FILE__, __LINE__, _T( exp ) ); }
#define OutputDebug( exp ) { MyLib::outputDebug( _T( exp ) ); }
#else 
#define ASSERT( x );
#define HALT( exp );
#define OutputDebug( exp );
#endif

#define ERROR_MES( exp ) { MyLib::showMessageBox( _T( exp ) ); }

#endif //#ifndef INCLUDED_PLUTILS_H