#include "HitArea.h"
#include "QuadTree.h"
#include "Figure/base.h"
#include "Figure/Circle.h"
#include "Figure/Rectangle.h"
#include "Figure/RotatedRect.h"
#include "Figure/Point2D.h"
#include "../PlUtils.h"
	#include "DxLib.h"
#include <cmath>

namespace Object{

HitArea::HitArea() : mAreaNum( 0 , 0 ),
mAreaInitalized( false ){
	mQuadTree = QuadTree::instance();
}

HitArea::HitArea(const Object::HitArea &other) : mVector( other.mVector ),
mAreaNum( other.mAreaNum ),
mQuadTree( other.mQuadTree ),
mAreaInitalized( other.mAreaInitalized ){
	if( mAreaInitalized ){
		mAreaBottom = Pt2Ptr( new Point2D( *other.mAreaBottom ) );
		mAreaTop = Pt2Ptr( new Point2D( *other.mAreaTop ) );
	}
}

HitArea::~HitArea(){
	/*foreach( Figure* s , mVector ){
		SAFE_DELETE( s );
	}*/
	mVector.clear();
	
}

void HitArea::addCircle(float x, float y, float r){
	if( !mAreaInitalized ){
		mAreaTop = Pt2Ptr( new Point2D( x - r , y - r ) );
		mAreaBottom = Pt2Ptr( new Point2D( x + r , y + r ) );
		mAreaInitalized = true;
	}else{
		setAreaPos( x - r , y - r , x + r , y + r );
	}
	mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	mVector.push_back( FigPtr( new Circle( x , y , r ) ) );
}

void HitArea::addRectangle(float x1, float y1, float x2, float y2){
	if( !mAreaInitalized ){
		mAreaTop = Pt2Ptr( new Point2D( x1 , y1 ) );
		mAreaBottom = Pt2Ptr( new Point2D( x2 , y2 ) );
		mAreaInitalized = true;
	}else{
		setAreaPos( x1 , y1 , x2 , y2 );
	}
	mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	mVector.push_back( FigPtr( new Rectangle( x1 , y1 , x2 , y2 ) ) );
}

void HitArea::addRotatedRect(float cx, float cy, float width, float height, float angle){
	if( !mAreaInitalized ){
		float t = sqrt( width * width + height * height );
		mAreaTop = Pt2Ptr( new Point2D( cx - t , cy - t ) );
		mAreaBottom = Pt2Ptr( new Point2D( cx + t , cy + t ) );
		mAreaInitalized = true;
	}else{
		float t = sqrt( width * width + height * height );
		setAreaPos( cx - t , cy - t , cx + t , cy + t );
	}
	mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	mVector.push_back( FigPtr( new RotatedRect( cx , cy , width , height , angle ) ) );
}

void HitArea::addArea( Figure* ptr ){
	// Fix it!
	FigPtr buf;
	Rectangle* rect;
	Circle* cir;
	RotatedRect* rrect;
	switch( ptr->id() ){
		case Figure::F_RECTANGLE:
			rect = new Rectangle( *static_cast< Rectangle* >( ptr ) );
			buf = FigPtr( rect );
			if( !mAreaInitalized ){
				mAreaTop = Pt2Ptr( new Point2D( rect->getLeftTop() ) );
				mAreaBottom = Pt2Ptr( new Point2D( rect->getRightBottom() ) );
				mAreaInitalized = true;
			}else{
				setAreaPos( rect->getLeftTop().getX() , rect->getLeftTop().getY() , rect->getRightBottom().getX() , rect->getRightBottom().getY() );
			}
			break;
		case Figure::F_CIRCLE:
			cir = new Circle( *static_cast< Circle* >( ptr ) );
			buf = FigPtr( cir );
			if( !mAreaInitalized ){
				float r = cir->getRadius();
				mAreaTop = Pt2Ptr( new Point2D( cir->getCenter() ) );
				mAreaTop->add( -r, -r );
				mAreaBottom = Pt2Ptr( new Point2D( cir->getCenter() ) );
				mAreaBottom->add( r, r );
				mAreaInitalized = true;
			}else{
				float r = cir->getRadius();
				Point2D& cen = cir->getCenter();
				setAreaPos( cen.getX() - r , cen.getY() - r , cen.getX() + r , cen.getY() + r );
			}
			break;
		case Figure::F_ROTATED_RECT:
			rrect = new RotatedRect( *static_cast< RotatedRect* >( ptr ) );
			buf = FigPtr( rrect );
			if( !mAreaInitalized ){
				float t = sqrt( rrect->width() * rrect->width() + rrect->height() * rrect->height() );
				Point2D& center = rrect->getCenter();
				float cx = center.getX();
				float cy = center.getY();
				mAreaTop = Pt2Ptr( new Point2D( cx - t , cy - t ) );
				mAreaBottom = Pt2Ptr( new Point2D( cx + t , cy + t ) );
				mAreaInitalized = true;
			}else{
				float t = sqrt(rrect->width() * rrect->width() + rrect->height() * rrect->height() );
				Point2D& center = rrect->getCenter();
				float cx = center.getX();
				float cy = center.getY();
				setAreaPos( cx - t , cy - t , cx + t , cy + t );
			}
			break;
		default:
			HALT( "Unknown Figure Type." );
	}
	mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	mVector.push_back( buf );
}

void HitArea::destroy(){
	/*foreach( Figure* s , mVector ){
		SAFE_DELETE( s );
	}*/
	mVector.clear();
}

void HitArea::draw(){
	foreach( FigPtr& s , mVector ){
		s->draw();
	}
		DrawFormatString( mAreaTop->getXToInt(), mAreaTop->getYToInt(), GetColor(255, 255, 255), "(%d,%d)", mAreaNum.level(), mAreaNum.number() );
}

bool HitArea::isHit(HitArea &other){
	if( mAreaNum.isHit( other.mAreaNum ) ){
		foreach( FigPtr& s , mVector ){
			foreach( FigPtr& t , other.mVector ){
				if( s->isHit( *t ) ) return true;
			}
		}
	}
	return false;
}

bool HitArea::isHit(Object::Figure& other){
	if( !mVector.empty() ){
		foreach( FigPtr& s , mVector ){
			if( s->isHit( other ) ) return true;
		}
	}
	return false;
}

void HitArea::move(float x, float y){
	if( !mVector.empty() ){
		foreach( FigPtr& s , mVector ){
			s->move( x , y );
		}
		mAreaBottom->add( x , y );
		mAreaTop->add( x , y );
		mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	}
}

void HitArea::moveTo(float x, float y){
	if( !mVector.empty() ){
		foreach( FigPtr& s , mVector ){
			s->moveTo( x , y );
		}
		Point2D t( *mAreaBottom + *mAreaTop );
		t = t / 2.f;
		float tx = x - t.getX();
		float ty = y - t.getY();
		mAreaBottom->add( tx , ty );
		mAreaTop->add( tx , ty );
		mAreaNum = mQuadTree->getQuadNode( *mAreaTop, *mAreaBottom );
	}
}

void HitArea::setAreaPos(float x1, float y1, float x2, float y2){
	mAreaTop->set( min( mAreaTop->getX() , x1 ) , min( mAreaTop->getY() , y1 ) ); 
	mAreaBottom->set( max( mAreaBottom->getX() , x2 ) , max( mAreaBottom->getY() , y2 ) ); 
}


}