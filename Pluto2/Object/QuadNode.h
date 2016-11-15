#ifndef INCLUDED_OBJECT_QUADNODE_H
#define INCLUDED_OBJECT_QUADNODE_H

namespace Object{

class QuadNode{
public:
	QuadNode( int number, int level );
	QuadNode( const QuadNode& other );
	~QuadNode();

	bool isHit( const QuadNode& other );
	int number() const;
	int level() const;
private:
	int mNumber;
	int mLevel;
};

}

#endif //#ifndef INCLUDED_OBJECT_QUADNODE_H