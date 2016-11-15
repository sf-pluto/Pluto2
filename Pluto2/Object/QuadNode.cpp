#include "QuadNode.h"

namespace Object{

QuadNode::QuadNode( int number , int level ) : mNumber( number ),
mLevel( level ){
}

QuadNode::QuadNode(const Object::QuadNode &other) : mNumber( other.mNumber ),
mLevel( other.mLevel ){
}

QuadNode::~QuadNode(){
}

bool QuadNode::isHit(const Object::QuadNode &other){
	if( mLevel > other.mLevel ){
		return ( ( ( mNumber ^ other.mNumber ) >> ( mLevel * 2 ) ) & 0x00000003 ) == 0;
	}else if( mLevel == other.mLevel ){
		return mNumber == other.mNumber;
	}else{
		return ( ( ( mNumber ^ other.mNumber ) >> ( other.mLevel * 2 ) ) & 0x00000003 ) == 0;
	}
}

int QuadNode::number() const{
	return mNumber;
}

int QuadNode::level() const{
	return mLevel;
}

}