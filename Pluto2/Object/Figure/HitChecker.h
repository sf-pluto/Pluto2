#include "base.h"
#include "../../Class/Singleton.h"

namespace Object{

class Vector2D;

namespace HitCheck{

bool doHitCheck( Figure& lhs ,  Figure& rhs ); 
bool checkRectRect( Figure& lhs , Figure& rhs );
bool checkCircCirc( Figure& lhs , Figure& rhs );
bool checkRectCirc( Figure& lhs , Figure& rhs );
bool checkRrectRrect( Figure& lhs , Figure& rhs );
bool checkRrectCirc( Figure& lhs , Figure& rhs );

float absDot( Vector2D& lhs , Vector2D& rhs );

}

}