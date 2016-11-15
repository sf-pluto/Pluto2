#pragma warning(disable: 4996)
#include "Network.h"
#include "DxLib.h"
#include "../PlUtils.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace boost;
using namespace boost::algorithm;

namespace Object{

Network::Network() : mHandle( 0 ),
mIsConnected( false ),
mIsListening( false ){
}

Network::~Network(){
	if( mIsConnected ) CloseNetWork( mHandle );
}

bool Network::connect(std::string &IP, int port){
	IPDATA data;
	vector<string> v;
	split( v , IP , is_any_of( "." ) );
	data.d1 = static_cast< unsigned char >( lexical_cast< int >( v[ 0 ] ) );
	data.d2 = static_cast< unsigned char >( lexical_cast< int >( v[ 1 ] ) );
	data.d3 = static_cast< unsigned char >( lexical_cast< int >( v[ 2 ] ) );
	data.d4 = static_cast< unsigned char >( lexical_cast< int >( v[ 3 ] ) );
	mHandle = ConnectNetWork( data , port );
	if( mHandle != -1 ){
		mIsConnected = true;
		return true;
	}
	return false;
}

bool Network::listen(int port){
	if( !mIsListening ) PreparationListenNetWork( port );
	mHandle = GetNewAcceptNetWork();
	if( mHandle != -1 ){
		mIsConnected = true;
		StopListenNetWork();
		return true;
	}
	return false;
}

bool Network::send(void *buf, int length){
	return ( NetWorkSend( mHandle , buf , length ) == 0 ) ? true : false;
}

bool Network::receive(void *buf, int length){
	return ( NetWorkRecv( mHandle , buf , length ) == 0 ) ? true : false;
}

void Network::close(){
	if( mIsConnected ) CloseNetWork( mHandle );
	mIsConnected = false;
}

}