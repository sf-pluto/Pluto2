#ifndef INCLUDED_CLASS_SINGLETON_H
#define INCLUDED_CLASS_SINGLETON_H

#include <boost/thread.hpp>
#include "../PlUtils.h"

template< typename T >
class Singleton : private boost::noncopyable{
public:
	static T* instance();
	static void destroy();
private:
	static void init();
	static T* mInstance;
};

template< typename T >
T* Singleton< T >::instance(){
	static boost::once_flag once = BOOST_ONCE_INIT;
	boost::call_once( init , once );
    return mInstance;
}

template< typename T >
void Singleton< T >::init(){
	mInstance = new T;
}

template< typename T >
void Singleton< T >::destroy(){
	ASSERT( mInstance );
	SAFE_DELETE( mInstance );
}

template< typename T >
T* Singleton< T >::mInstance = NULL;


#endif //#ifndef INCLUDED_CLASS_SINGLETON_H