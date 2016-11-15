#define _USE_MATH_DEFINES // for C++

#include "../PlUtils.h"
#include "../Lua/LuaUtils.h"
#include "Image.h"
#include "GameObject.h"
#include "GameObjectGroup.h"
#include "ObjectManager.h"
#include "HitArea.h"
#include "Figure/base.h"
#include "Figure/Circle.h"
#include "../Lua/LuaCurrentState.h"
#include "../Input/Mouse.h"
#include <cmath>
#include <boost/lexical_cast.hpp>

using namespace Input;

namespace Object{

GameObject::GameObject() : mImage(0){
}

GameObject::GameObject(const Object::Image &image, float x, float y) : mImage( image ),
mX( x ),
mY( y ),
mVX( 0.0f ),
mVY( 0.0f ),
mHP( 1 ),
mFrame( 0 ),
mAngle( 0.0f ),
mSpeed( 0.0f ),
mIsDead( false ),
mVisible( true ),
mHitArea( new HitArea() ){
	mState = LuaCurrentState::instance()->getState();
	mObserver = ObjectManager::instance()->registerObject( this );
}

GameObject::GameObject(const Object::Image &image, float x, float y, float angle) : mImage( image ),
mX( x ),
mY( y ),
mVX( 0.0f ),
mVY( 0.0f ),
mFrame( 0 ),
mHP( 1 ),
mAngle( angle ),
mSpeed( 0.0f ),
mIsDead( false ),
mVisible( true ),
mHitArea( new HitArea() ){
	mState = LuaCurrentState::instance()->getState();
	mObserver = ObjectManager::instance()->registerObject( this );
}

GameObject::GameObject(const Object::Image &image, float x, float y, float angle, float speed) : mImage( image ),
mX( x ),
mY( y ),
mVX( cos( angle ) * speed ),
mVY( sin( angle ) * speed ),
mHP( 1 ),
mFrame( 0 ),
mAngle( angle ),
mSpeed( speed ),
mIsDead( false ),
mVisible( true ),
mHitArea( new HitArea() ){
	mState = LuaCurrentState::instance()->getState();
	mObserver = ObjectManager::instance()->registerObject( this );
}

GameObject::GameObject(const Object::GameObject &other) : mImage( other.mImage ),
mX( other.mX ),
mY( other.mY ),
mVX( other.mVX ),
mVY( other.mVY ),
mHP( other.mHP ),
mWhenDied( other.mWhenDied ),
mAction( other.mAction ),
mAngle( other.mAngle ),
mIsDead( other.mIsDead ),
mVisible( other.mVisible ),
mFrame( other.mFrame ),
mSpeed( other.mSpeed ),
mState( other.mState ){
	mHitArea = new HitArea( *other.mHitArea );
	mObserver = ObjectManager::instance()->registerObject( this );
}

GameObject::~GameObject(){
	// ŸŽè‚ÉŒÄ‚Î‚ê‚é
	 SAFE_DELETE( mHitArea );
	 mObserver->mIsAlive = false;
}

GameObject& GameObject::operator =(const GameObject &other){
	mX = other.mX;
	mY = other.mY;
	mVX = other.mVX;
	mVY = other.mVY;
	mHP = other.mHP;
	mVisible = other.mVisible;
	mAction = other.mAction;
	mAngle = other.mAngle;
	mFrame = other.mFrame;
	mSpeed = other.mSpeed;
	mState = other.mState;
	mHitArea = new HitArea( *other.mHitArea );
	return *this;
}


void GameObject::move(){
	mX += mVX;
	mY += mVY;
	mHitArea->move( mVX , mVY );
}

void GameObject::move(float x, float y){
	mX += x;
	mY += y;
	mHitArea->move( x , y );
}

void GameObject::moveTo(float x, float y){
	mX = x;
	mY = y;
	mHitArea->moveTo( x , y );
}

void GameObject::doAction(){
	if( !mAction.empty() ){
		luabind::call_function< void >( mState , mAction.c_str() , this );
		//if( mIsDead ) this->~GameObject();
		//else 
	}
}

void GameObject::draw(){
	if( mVisible ){
		mImage.drawCenterF( mX , mY );
	}
}

void GameObject::drawRotate(){
	if( mVisible ){
		mImage.drawRotate( mX , mY , -M_PI / 2 + mAngle );
	}
}

void GameObject::drawHitArea(){
	mHitArea->draw();
}

std::string GameObject::toString(){
	string s;
	s+="X: ";
	s+=boost::lexical_cast< string >( mX );
	s+="\nY: ";
	s+=boost::lexical_cast< string >( mY );
	s+="\nVX: ";
	s+=boost::lexical_cast< string >( mVX );
	s+="\nVY: ";
	s+=boost::lexical_cast< string >( mVY );
	s+="\nAngle: ";
	s+=boost::lexical_cast< string >( mAngle );
	s+="\nSpeed: ";
	s+=boost::lexical_cast< string >( mSpeed );
	s+="\nHP: ";
	s+=boost::lexical_cast< string >( mHP );
	s+="\nFrame: ";
	s+=boost::lexical_cast< string >( mFrame );
	s+="\nAction: ";
	s+=mAction;
	s+="\n";
	return s;
}

void GameObject::addHitArea(Object::Figure *area){
	mHitArea->addArea( area );
}

void GameObject::addCircle(float x, float y, float r){
	mHitArea->addCircle( x , y , r );
}

void GameObject::addRectangle(float x1, float y1, float x2, float y2){
	mHitArea->addRectangle( x1 , y1 , x2 , y2 );
}

void GameObject::addRotatedRect(float cx, float cy, float width, float height, float angle){
	mHitArea->addRotatedRect( cx , cy , width , height , angle );
}

void GameObject::addAngle(float val){
	mAngle += val;
	mVX = cos( mAngle ) * mSpeed;
	mVY = sin( mAngle ) * mSpeed;
}

void GameObject::addSpeed(float val){
	mSpeed += val;
	mVX = cos( mAngle ) * mSpeed;
	mVY = sin( mAngle ) * mSpeed;
}

void GameObject::addFrame(){
	mFrame++;
}

void GameObject::addVelocity(float x, float y){
	mVX += x;
	mVY += y;
	mAngle = atan2( mVX , mVY );
	mSpeed = sqrt( mVX * mVX + mVY + mVY );
}

void GameObject::setValue(const std::string &str, int val){
	mValue[str] = val;
}

void GameObject::setAction(const std::string &str){
	mAction = str;
}

void GameObject::setWhenDied(const std::string &str){
	mWhenDied = str;
}

void GameObject::setAngle(float val){
	mAngle = val;
	mVX = cos( val ) * mSpeed;
	mVY = sin( val ) * mSpeed;
}

void GameObject::setSpeed(float val){
	mSpeed = val;
	mVX = cos( mAngle ) * val;
	mVY = sin( mAngle ) * val;
}

void GameObject::setVelocity(float x, float y){
	mVX = x;
	mVY = y;
	mAngle = atan2( x , y );
	mSpeed = sqrt( x * x + y * y );
}

void GameObject::setVisible(bool val){
	mVisible = val;
}

void GameObject::addHP(int val){
	mHP += val;
	if( mHP <= 0 ) die();
}

void GameObject::setHP(int val){
	mHP = val;
	if( mHP <= 0 ) die();
}

void GameObject::die(){
	if( !mWhenDied.empty() && !mIsDead ){
		luabind::call_function< void >( mState , mWhenDied.c_str() , this ); 
	}
	mIsDead = true;
}

void GameObject::destroyHitArea(){
	mHitArea->destroy();
}

int GameObject::getValue(const std::string &str){
	return mValue[str];
}

float GameObject::getX() const{
	return mX;
}

float GameObject::getY() const{
	return mY;
}

float GameObject::getVX() const{
	return mVX;
}

float GameObject::getVY() const{
	return mVY;
}

GameObject& GameObject::getHitObject() const{
	return *mHitObject;
}

float GameObject::angle() const{
	return mAngle;
}

float GameObject::speed() const{
	return mSpeed;
}

bool GameObject::isHit(const Object::GameObject &other){
	return other.mHitArea->isHit( *mHitArea );
}
bool GameObject::isHit(const Object::GameObjectGroup &group){
	foreach( const Object::GameObjectGroup::ObjPtr& obj , group.getObjectList() ){
		if( obj->mHitArea->isHit( *mHitArea ) ){
			mHitObject = &*obj;
			return true;
		}
	}
	return false;
}
bool GameObject::isHit(const Object::GameObjectGroup &group, Object::GameObject &obj){
	foreach( const Object::GameObjectGroup::ObjPtr& iobj , group.getObjectList() ){
		if( iobj->mHitArea->isHit( *mHitArea ) ){
			obj = *iobj;
			return true;
		}
	}
	return false;
}

bool GameObject::isDead(){
	return mIsDead;
}

bool GameObject::isOutOfWindow(){
	return mImage.isOutOfWindowF( mX , mY );
}

bool GameObject::isClicked(){
	if( Mouse::instance()->isMouseInputed( 0x0001 ) ){ 
		return mHitArea->isHit( Circle( Mouse::instance()->getMousePosition() , 1.f ) );
	}
	return false;
}

const Image& GameObject::getImage(){
	return mImage;
}

int GameObject::frame() const{
	return mFrame;
}

int GameObject::getHP() const{
	return mHP;
}

}