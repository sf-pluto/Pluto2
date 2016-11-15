#include "HitChecker.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RotatedRect.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <boost/cast.hpp>
#include <cmath>

namespace Object{

namespace HitCheck{

bool doHitCheck( Figure& lhs , Figure& rhs ){
	Figure::F_TYPE ltype = lhs.id();
	Figure::F_TYPE rtype = rhs.id();
	if( ltype == Figure::F_CIRCLE && rtype == Figure::F_CIRCLE ) return checkCircCirc( lhs , rhs );
	if( ltype == Figure::F_RECTANGLE && rtype == Figure::F_RECTANGLE ) return checkRectRect( lhs , rhs );
	if( ltype == Figure::F_RECTANGLE && rtype == Figure::F_CIRCLE ) return checkRectCirc( lhs , rhs );
	if( ltype == Figure::F_CIRCLE && rtype == Figure::F_RECTANGLE ) return checkRectCirc( rhs , lhs );
	if( ltype == Figure::F_ROTATED_RECT && rtype == Figure::F_ROTATED_RECT ) return checkRectCirc( rhs , lhs );
	return false;
}

bool checkRectRect(Object::Figure &lhs, Object::Figure &rhs){
	Rectangle& lrect = static_cast< Rectangle& >( lhs );
	Rectangle& rrect = static_cast< Rectangle& >( rhs );
	Point2D& llt = lrect.getLeftTop();
	Point2D& lrb = lrect.getRightBottom();
	Point2D& rlt = rrect.getLeftTop();
	Point2D& rrb = rrect.getRightBottom();
	return ( llt.getX() < rrb.getX() && rlt.getX() < lrb.getX() && llt.getY() < rrb.getY() && rlt.getY() < lrb.getY() ) ? true : false;
}

bool checkCircCirc(Object::Figure &lhs, Object::Figure &rhs){
	Circle& lcirc = static_cast< Circle& >( lhs );
	Circle& rcirc = static_cast< Circle& >( rhs );
	Point2D cent = lcirc.getCenter() - rcirc.getCenter();
	float lrad = lcirc.getRadius();
	float rrad = rcirc.getRadius();
	return ( cent.getPowLength() < ( lrad + rrad ) * ( lrad + rrad ) ) ? true : false;
}

bool checkRectCirc(Object::Figure &lhs, Object::Figure &rhs){
	Rectangle& rect = static_cast< Rectangle& >( lhs );
	Circle& circ = static_cast< Circle& >( rhs );

	Point2D rcent = rect.getLeftTop();
	Vector2D& vr = rect.getVector();
	rcent.add( vr.getX() , vr.getY() );
	Point2D& cent = circ.getCenter();
	float rad = circ.getRadius();

	if( fabsf( rcent.getX() - cent.getX() ) >= rad + fabsf( vr.getX() ) ) return false;
	if( fabsf( rcent.getY() - cent.getY() ) >= rad + fabsf( vr.getY() ) ) return false;
	// ‰~‚ª‹éŒ`‚É•ïŠÜ‚³‚ê‚Ä‚¢‚é‚©
	Point2D& rlt = rect.getLeftTop();
	Point2D& rrb = rect.getRightBottom();
	if( cent.getX() < rrb.getX() && rlt.getX() < cent.getX() && cent.getY() > rlt.getY() && rrb.getY() > cent.getY() ) return true;
	// ‹éŒ`‚ÌŠp‚ª‰~‚ÉŠÜ‚Ü‚ê‚Ä‚¢‚é‚©
	if( ( rlt - cent ).getLength() < rad ) return true;
	if( ( rrb - cent ).getLength() < rad ) return true;
	if( ( rect.getLeftBottom() - cent ).getLength() < rad ) return true;
	if( ( rect.getRightTop() - cent ).getLength() < rad ) return true;

	// ‚»‚êˆÈŠO‚È‚ç‚Î“–‚½‚Á‚Ä‚¢‚È‚¢
	return false;

	//Point2D& rlt = rect.getLeftTop();
	//Point2D& rrb = rect.getRightBottom();
	//Point2D& cent = circ.getCenter();
	//float rad = circ.getRadius();


	////@‰~‚ª‹éŒ`‚É•ïŠÜ‚³‚ê‚Ä‚¢‚é‚©
	//if( cent.getX() < rrb.getX() && rlt.getX() < cent.getX() && cent.getY() > rlt.getY() && rrb.getY() > cent.getY() ) return true;
	//
	////@‹éŒ`‚ª‰~‚É•ïŠÜ‚³‚ê‚Ä‚¢‚é‚©
	//if( ( ( rlt + rrb ) / 2 - cent ).getLength() < rad ) return true;

	//Rectangle crect( Point2D( cent.getX() - rad , cent.getY() - rad ) , Point2D( cent.getX() + rad , cent.getY() + rad ) );
	//Point2D llt = crect.getLeftTop();
	//Point2D lrb = crect.getRightBottom();
	//// ‰~‚Ìü‚è‚É‹éŒ`‚ğì‚èd‚È‚Á‚Ä‚¢‚È‚¯‚ê‚Î”»’è‚ğ‚µ‚È‚¢
	//if( !( llt.getX() < rrb.getX() && rlt.getX() < lrb.getX() && llt.getY() < rrb.getY() && rlt.getY() < lrb.getY() ) ) return false;

	//float cl = cent.getX() - rad;
	//float cr = cent.getX() + rad;
	//float ct = cent.getY() - rad;
	//float cb = cent.getY() + rad;
	////@’¼Œa‚ª‹éŒ`‚ÆŒğ·‚µ‚Ä‚¢‚é‚©
	//if( cl < rlt.getX() && rlt.getX() < cr && rlt.getY() < cent.getY() && cent.getY() < rrb.getY() ) return true;
	//if( cl < rrb.getX() && rrb.getX() < cr && rlt.getY() < cent.getY() && cent.getY() < rrb.getY() ) return true;
	//if( ct < rlt.getY() && rlt.getY() < cb && rlt.getX() < cent.getX() && cent.getX() < rrb.getX() ) return true;
	//if( cl < rrb.getY() && rrb.getY() < cr && rlt.getX() < cent.getX() && cent.getX() < rrb.getX() ) return true;

	//// ‹éŒ`‚ÌŠp‚ª‰~‚ÉŠÜ‚Ü‚ê‚Ä‚¢‚é‚©
	//if( ( rlt - cent ).getLength() < rad ) return true;
	//if( ( rrb - cent ).getLength() < rad ) return true;
	//if( ( rect.getLeftBottom() - cent ).getLength() < rad ) return true;
	//if( ( rect.getRightTop() - cent ).getLength() < rad ) return true;
	//
	//// ‚»‚êˆÈŠO‚È‚ç‚Î“–‚½‚Á‚Ä‚¢‚È‚¢
	//return false;
}

bool checkRrectRrect(Object::Figure &lhs, Object::Figure &rhs){
	RotatedRect& a = static_cast< RotatedRect& >( lhs );
	RotatedRect& b = static_cast< RotatedRect& >( rhs );
	Vector2D dist( a.getCenter() - b.getCenter() );
	
	float aAng = a.angle();
	Vector2D ea1( cos( aAng ) * a.width() / 2 , sin( aAng ) * a.width() / 2 );
	Vector2D ea2( cos( aAng ) * a.height() / 2 , sin( aAng ) * a.height() / 2 );
	float bAng = b.angle();
	Vector2D eb1( cos( bAng ) * b.width() / 2 , sin( bAng ) * b.width() / 2 );
	Vector2D eb2( cos( bAng ) * b.height() / 2 , sin( bAng ) * b.height() / 2 );
	// getLength may be nonsense
	Vector2D nea1( ea1 );
	nea1.normalize();
	if( absDot( dist , nea1 ) >= ea1.getLength() + absDot( eb1 , nea1 ) + absDot( eb2 , nea1 ) ) return false;

	Vector2D nea2( ea2 );
	nea2.normalize();
	if( absDot( dist , nea2 ) >= ea2.getLength() + absDot( eb1 , nea2 ) + absDot( eb2 , nea2 ) ) return false;

	Vector2D neb1( eb1 );
	neb1.normalize();
	if( absDot( dist , neb1 ) >= eb1.getLength() + absDot( ea1 , neb1 ) + absDot( ea2 , neb1 ) ) return false;

	Vector2D neb2( eb2 );
	neb2.normalize();
	if( absDot( dist , neb2 ) >= eb2.getLength() + absDot( ea1 , neb2 ) + absDot( ea2 , neb2 ) ) return false;

	return true;
}

bool checkRrectCirc(Object::Figure &lhs, Object::Figure &rhs){
	RotatedRect& r = static_cast< RotatedRect& >( lhs );
	Circle& c = static_cast< Circle& >( rhs );
	Vector2D d( r.getCenter() - c.getCenter() );

	float ang = r.angle();
	Vector2D a1( cos( ang ) * r.width() / 2 , sin( ang ) * r.width() / 2 );
	Vector2D a2( cos( ang ) * r.height() / 2 , sin( ang ) * r.height() / 2 );

	a1.normalize();
	if( absDot( d , a1 ) >= r.width() + c.getRadius() ) return false;
	a2.normalize();
	if( absDot( d , a2 ) >= r.height() + c.getRadius() ) return false;

	// Do NOT forget implementing following code!

	return true;

	/*Point2D& rc = r.getCenter();
	Point2D& cc = c.getCenter();*/
}

inline float absDot(Vector2D &lhs , Vector2D &rhs){
	return fabsf( Vec2Dot( lhs , rhs ) );
}

}

}