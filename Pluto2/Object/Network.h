#ifndef INCLUDED_OBJECT_NETWORK_H
#define INCLUDED_OBJECT_NETWORK_H

#include <string>

using namespace std;

namespace Object{

class Network{
public:
	Network();
	~Network();

	bool connect( string& IP , int port );
	bool send( void* buf , int length );
	void close();
	bool listen( int port );
	bool receive( void* buf , int length );
private:
	int mHandle;
	bool mIsConnected;
	bool mIsListening;
};

}

#endif //#ifndef INCLUDED_OBJECT_NETWORK_H