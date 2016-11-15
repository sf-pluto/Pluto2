#include "LuaBindDirectX.h"
#include "DxLib.h"

#define _USE_MATH_DEFINES // for C++
#define M_PI 3.14159265358979323846

#include "../PlUtils.h"
#include "../LogWritter.h"
#include "LuaCurrentState.h"
#include "LuaUtils.h"
#include "LuaConstantChecker.h"
#include <luabind/operator.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/timer.hpp>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "../Utility/FpsControl.h"
#include "../Input/Keyboard.h"
#include "../Input/JoyPad.h"
#include "../Input/Mouse.h"
#include "../Scene/Parent.h"
#include "../Object/Image.h"
#include "../Object/Sound.h"
#include "../Object/Animation.h"
#include "../Object/Font.h"
#include "../Object/Const.h"
#include "../Object/GameObject.h"
#include "../Object/ObjectManager.h"
#include "../Object/GameObjectGroup.h"
#include "../Object/UserObject.h"
#include "../Object/Network.h"
#include "../Object/Figure/base.h"
#include "../Object/Figure/Point2D.h"
#include "../Object/Figure/Line.h"
#include "../Object/Figure/Rectangle.h"
#include "../Object/Figure/Circle.h"

using namespace std;
using namespace luabind;

void moveScene( const char *filename );
void setTitle( const char* x );
void writeLog( const string& str );
void writelnLog( const string& str );
void writeTimeLog( const string& str );
void setMouseVisible( int flag );
void setFpsInterval( int val );
void quit();
bool isButtonPressed( int key );
bool isMouseInputed( int button );
float getFps();
float deg( float n );
float rad( float n );
float myabs( float f );
float mymax( float l , float r );
float mymin( float l , float r );
float mypow( float l , float r );


LuaBindDirectX::LuaBindDirectX(){
	 //Luaを開く
	mLua = lua_open();
}

//#define SET_KEYCONST(z, n, data) \
//	setConstant( mLua, BOOST_PP_CAT( KEY_, n ), BOOST_PP_CAT( KEY_, n ) ); \

LuaBindDirectX::LuaBindDirectX(const char *filename) : mFilename( filename ){
	typedef boost::shared_ptr< Object::Point2D > Point2DPtr;
	 
	//Luaを開く
    /*mLua = lua_open();
	luabind::open( mLua );*/
	mLua = initLuaBind();
	
    //Luaの標準関数を使用できる状態にする
    luaL_openlibs( mLua );

	//lua_gc( mLua , LUA_GCSTOP , 0 );
	//lua_gc( mLua , LUA_GCSETSTEPMUL , 1000 );

	int colorred = GetColor( 255 , 0 , 0 );
	int colorblue = GetColor( 0 , 0 , 255 );
	int colorgreen = GetColor( 0 , 255 , 0 );
	int colorwhite = GetColor( 255 , 255 , 255 );

	// 真偽
	setConstant( mLua , "TRUE" , TRUE );
	setConstant( mLua , "FALSE" , FALSE );
	// 色
	setConstant( mLua , "RED" , colorred );
	setConstant( mLua , "BLUE" , colorblue );
	setConstant( mLua , "GREEN" , colorgreen );
	setConstant( mLua , "WHITE" , colorwhite );
	// 数学
	setConstant( mLua , "PI" , M_PI );
	//setConstant( mLua , "E" , M_E );
	// キー
	setConstant( mLua , "KEY_0" , KEY_INPUT_0 );
	setConstant( mLua , "KEY_1" , KEY_INPUT_1 ); 
	setConstant( mLua , "KEY_2" , KEY_INPUT_2 );
	setConstant( mLua , "KEY_3" , KEY_INPUT_3 ); 
	setConstant( mLua , "KEY_4" , KEY_INPUT_4 );
	setConstant( mLua , "KEY_5" , KEY_INPUT_5 ); 
	setConstant( mLua , "KEY_6" , KEY_INPUT_6 ); 
	setConstant( mLua , "KEY_7" , KEY_INPUT_7 ); 
	setConstant( mLua , "KEY_8" , KEY_INPUT_8 );
	setConstant( mLua , "KEY_9" , KEY_INPUT_9 ); 
	setConstant( mLua , "KEY_A" , KEY_INPUT_A );
	setConstant( mLua , "KEY_B" , KEY_INPUT_B ); 
	setConstant( mLua , "KEY_C" , KEY_INPUT_C );
	setConstant( mLua , "KEY_D" , KEY_INPUT_D ); 
	setConstant( mLua , "KEY_E" , KEY_INPUT_E );
	setConstant( mLua , "KEY_F" , KEY_INPUT_F ); 
	setConstant( mLua , "KEY_G" , KEY_INPUT_G );
	setConstant( mLua , "KEY_H" , KEY_INPUT_H ); 
	setConstant( mLua , "KEY_I" , KEY_INPUT_I );
	setConstant( mLua , "KEY_J" , KEY_INPUT_J ); 
	setConstant( mLua , "KEY_K" , KEY_INPUT_K );
	setConstant( mLua , "KEY_L" , KEY_INPUT_L ); 
	setConstant( mLua , "KEY_M" , KEY_INPUT_M );
	setConstant( mLua , "KEY_N" , KEY_INPUT_N ); 
	setConstant( mLua , "KEY_O" , KEY_INPUT_O );
	setConstant( mLua , "KEY_P" , KEY_INPUT_P ); 
	setConstant( mLua , "KEY_Q" , KEY_INPUT_Q );
	setConstant( mLua , "KEY_R" , KEY_INPUT_R ); 
	setConstant( mLua , "KEY_S" , KEY_INPUT_S );
	setConstant( mLua , "KEY_T" , KEY_INPUT_T ); 
	setConstant( mLua , "KEY_U" , KEY_INPUT_U );
	setConstant( mLua , "KEY_V" , KEY_INPUT_V ); 
	setConstant( mLua , "KEY_W" , KEY_INPUT_W );
	setConstant( mLua , "KEY_X" , KEY_INPUT_X );
	setConstant( mLua , "KEY_Y" , KEY_INPUT_Y );
	setConstant( mLua , "KEY_Z" , KEY_INPUT_Z );
	setConstant( mLua , "KEY_LEFT" , KEY_INPUT_LEFT ); 
	setConstant( mLua , "KEY_RIGHT" , KEY_INPUT_RIGHT );
	setConstant( mLua , "KEY_UP" , KEY_INPUT_UP );
	setConstant( mLua , "KEY_DOWN" , KEY_INPUT_DOWN );
	setConstant( mLua , "KEY_LSHIFT" , KEY_INPUT_LSHIFT );
	setConstant( mLua , "KEY_RSHIFT" , KEY_INPUT_RSHIFT );
	// ボタン
	setConstant( mLua , "BUTTON_A" , PAD_INPUT_A );
	setConstant( mLua , "BUTTON_B" , PAD_INPUT_B );
	setConstant( mLua , "BUTTON_C" , PAD_INPUT_C );
	setConstant( mLua , "BUTTON_X" , PAD_INPUT_X );
	setConstant( mLua , "BUTTON_Y" , PAD_INPUT_Y );
	setConstant( mLua , "BUTTON_Z" , PAD_INPUT_Z );
	setConstant( mLua , "BUTTON_L" , PAD_INPUT_L );
	setConstant( mLua , "BUTTON_R" , PAD_INPUT_R );
	setConstant( mLua , "BUTTON_START" , PAD_INPUT_START );
	setConstant( mLua , "BUTTON_LEFT" , PAD_INPUT_LEFT ); 
	setConstant( mLua , "BUTTON_RIGHT" , PAD_INPUT_RIGHT );
	setConstant( mLua , "BUTTON_UP" , PAD_INPUT_UP );
	setConstant( mLua , "BUTTON_DOWN" , PAD_INPUT_DOWN );
	// マウス
	setConstant( mLua , "MOUSE_LEFT" , MOUSE_INPUT_LEFT );
	setConstant( mLua , "MOUSE_RIGHT" , MOUSE_INPUT_RIGHT );
	setConstant( mLua , "MOUSE_MIDDLE" , MOUSE_INPUT_MIDDLE );

	module(mLua) [
		// Math
		def( "abs" , &myabs ),
		def( "acos" , &acos ),
		def( "asin" , &asin ),
		def( "atan" , &atan ),
		def( "atan2" , &atan2 ),
		def( "cos" , &cos ),
		def( "cosh" , &cosh ),
		def( "exp" , &exp ),
		def( "floor" , &floor ),
		def( "frexp" , &frexp ),
		def( "ldexp" , &ldexp ),
		def( "log" , &log ),
		def( "log10" , &log10 ),
		def( "max" , &mymax ),
		def( "min" , &mymin ),
		def( "modf" , &modf ),
		def( "pow" , &mypow ),
		def( "sin" , &sin ),
		def( "sinh" , &sinh ),
		def( "sqrt" , &sqrt ),
		def( "tan" , &tan ),
		def( "tanh" , &tanh ),
		// Pluto
		def( "writeLog" , &writeLog ),
		def( "writelnLog" , &writelnLog ),
		def( "writeTimeLog" , &writeTimeLog ),
		def( "moveScene" , &moveScene ),
		def( "quit" , &quit ),
		// DirectX
		def( "isKeyPressed" , &Input::Keyboard::isKeyPressed ),
		def( "isButtonPressed" , &isButtonPressed ),
		def( "isMouseInputed" , &isMouseInputed ),
		def( "setMouseVisible" , &setMouseVisible ),
		def( "drawRect" , &DrawBox ),
		def( "drawString" , &DrawString ),
		def( "setTitle" , &setTitle ),
		def( "getFps" , &getFps ),
		def( "setFpsInterval" , &setFpsInterval ), 
		def( "getRandom" , &GetRand ),
		def( "setSeed" , &SRand ),

		// Class Definition
		class_< Object::Point2D >( "Point2D" )
			.def( constructor< float , float >() ),
		class_< Object::Figure >( "Figure" )
			.def( "isHit" , &Object::Figure::isHit ),
		class_< Object::Line , Object::Figure >( "Line" )
			.def( constructor< const Object::Point2D& , const Object::Point2D& >() )
			.def( constructor< const Point2DPtr& , const Point2DPtr& >() )
			.def( "draw" , &Object::Line::draw )
			.def( "setColor" , &Object::Line::setColor ),
		class_< Object::Rectangle , Object::Figure >( "Rectangle" )
			.def( constructor< const Object::Point2D& , const Object::Point2D& >() )
			.def( constructor< const Point2DPtr& , const Point2DPtr& >() )
			.def( constructor< const Object::Point2D& , float , float >() )
			.def( constructor< float , float , float , float >() )
			.def( "draw" , &Object::Rectangle::draw )
			.def( "setColor" , &Object::Rectangle::setColor )
			.def( "setFilled" , &Object::Rectangle::setFilled )
			.def( "move" , &Object::Rectangle::move ),
		class_< Object::Circle , Object::Figure >( "Circle" )
			.def( constructor< const Object::Point2D& , float >() )
			.def( constructor< float , float , float >() )
			.def( constructor< const Point2DPtr& , float >() )
			.def( "draw" , &Object::Circle::draw )
			.def( "setColor" , &Object::Circle::setColor )
			.def( "setFilled" , &Object::Circle::setFilled )
			.def( "move" , &Object::Circle::move ),
		class_< Object::Image >( "Image" )
			.def( constructor< const char* >() )
			.def( constructor< const Object::Image&, int, int, int, int >() )
			.def( "draw" , &Object::Image::draw )
			//.def( "derive" , &Object::Image::derive )
			.def( "drawCenter" , &Object::Image::drawCenter )
			.def( "drawRect" , &Object::Image::drawCenter )
			.def( "drawModi" , &Object::Image::drawModi )
			.def( "drawRotate" , &Object::Image::drawRotate ),
		class_< Object::Animation >( "Animation" )
			.def( constructor< const char* , int , int , int , int , int >() )
			.def( "draw" , &Object::Animation::draw )
			.def( "setInterval" , &Object::Animation::setInterval )
			.def( "swing" , &Object::Animation::swing ),
		class_< Object::Font >( "Font" )
			.def( constructor< const char* , int , int , int >() )
			.def( "draw" , &Object::Font::draw ),
		class_< Object::GameObject >( "Object" )
			.def( constructor<>() )
			.def( constructor< const Object::Image& , float , float >() )
			.def( constructor< const Object::Image& , float , float , float >() )
			.def( constructor< const Object::Image& , float , float , float , float >() )
			.def( "draw" , &Object::GameObject::draw )
			.def( "drawRotate" , &Object::GameObject::drawRotate )
			.def( "drawHitArea" , &Object::GameObject::drawHitArea )
			.def( "move" , ( void( Object::GameObject::* )( void ) ) &Object::GameObject::move )
			.def( "move" , ( void( Object::GameObject::* )( float , float ) ) &Object::GameObject::move )
			.def( "moveTo" , &Object::GameObject::moveTo )
			.def( "frame" , &Object::GameObject::frame )
			.def( "die" , &Object::GameObject::die )
			.def( "toString" , &Object::GameObject::toString )
			.def( "addHP" , &Object::GameObject::addHP )
			.def( "getX" , &Object::GameObject::getX )
			.def( "getY" , &Object::GameObject::getY )
			.def( "getVX" , &Object::GameObject::getVX )
			.def( "getVY" , &Object::GameObject::getVY )
			.def( "getHP" , &Object::GameObject::getHP )
			.def( "getValue" , &Object::GameObject::getValue )
			.def( "getHitObject" , &Object::GameObject::getHitObject )
			.def( "angle" , &Object::GameObject::angle )
			.def( "speed" , &Object::GameObject::speed )
			.def( "setAngle" , &Object::GameObject::setAngle )
			.def( "setSpeed" , &Object::GameObject::setSpeed )
			.def( "setVelocity" , &Object::GameObject::setVelocity )
			.def( "setVisible" , &Object::GameObject::setVisible )
			.def( "setHP" , &Object::GameObject::setHP )
			.def( "setValue" , &Object::GameObject::setValue )
			.def( "isHit" , ( bool( Object::GameObject::* )( const Object::GameObject& ) ) &Object::GameObject::isHit )
			.def( "isHit" , ( bool( Object::GameObject::* )( const Object::GameObjectGroup& ) ) &Object::GameObject::isHit )
			//.def( "isHit" , ( bool( Object::GameObject::* )( const Object::GameObjectGroup&, Object::GameObject& ) ) &Object::GameObject::isHit )
			.def( "isClicked" , &Object::GameObject::isClicked )
			.def( "isOutOfWindow" , &Object::GameObject::isOutOfWindow )
			.def( "addHitArea" , &Object::GameObject::addHitArea )
			.def( "addCircle" , &Object::GameObject::addCircle )
			.def( "addRectangle" , &Object::GameObject::addRectangle )
			.def( "addRotatedRect" , &Object::GameObject::addRectangle )
			.def( "addSpeed" , &Object::GameObject::addSpeed )
			.def( "addAngle" , &Object::GameObject::addAngle )
			.def( "addVelocity" , &Object::GameObject::addVelocity )
			.def( "setAction" , &Object::GameObject::setAction )
			.def( "setWhenDied" , &Object::GameObject::setWhenDied )
			.def( "getImage" , &Object::GameObject::getImage )
			.def( "doAction" , &Object::GameObject::doAction ),
		class_< Object::Const >( "Const" )
			.def( constructor< float >() ),
		class_< Object::GameObjectGroup >( "ObjectGroup" )
			.def( constructor<>() )
			.def( "doFunction" , &Object::GameObjectGroup::doFunction )
			//.def( "setFunction" , ( void( Object::GameObjectGroup::* )( luabind::adl::object* ) ) &Object::GameObjectGroup::setFunction )
			.def( "setFunction" , &Object::GameObjectGroup::setFunction )
			.def( "setAction" , &Object::GameObjectGroup::setAction )
			.def( "createObject" , &Object::GameObjectGroup::createObject )
			.def( "setHP" , &Object::GameObjectGroup::setHP )
			.def( "setVisible" , &Object::GameObjectGroup::setVisible )
			.def( "count" , &Object::GameObjectGroup::count )
			.def( "addObject" , &Object::GameObjectGroup::addObject ),
		class_< Object::UserObject >( "Script" )
			.def( constructor< const char* >() )
			.def( "update" , &Object::UserObject::update ),
		class_< Object::Sound >( "Sound" )
			.def( constructor< const char* >() )
			.def( "play" , &Object::Sound::play )
			.def( "stop" , &Object::Sound::stop )
			.def( "setAsLoop" , &Object::Sound::setAsLoop )
			.def( "setPanpot" , &Object::Sound::setPanpot )
			.def( "setVolume" , &Object::Sound::setVolume )
			.def( "setFrequency" , &Object::Sound::setFrequency )
			.def( "setLoopPosition" , &Object::Sound::setLoopPosition )
			.def( "setPosition" , &Object::Sound::setPosition ),
		class_< Object::Network >( "Network" )
			.def( constructor<>() )
			.def( "connect" , &Object::Network::connect )
			.def( "send" , &Object::Network::send )
			.def( "close" , &Object::Network::close )
			.def( "listen" , &Object::Network::listen )
			.def( "receive" , &Object::Network::receive ),
		class_< boost::timer >( "Timer" )
			.def( constructor<>() )
			.def( "elapsed" , &boost::timer::elapsed )
	];

	/*if( luaL_dofile( mLua , filename ) ){
		string mes = lua_tostring( mLua , -1 );
		HALT( mes.c_str() );
	}*/

	// Load lua script file
	int fileHandle = FileRead_open( filename );
	if( fileHandle == 0 ){
		HALT( "Script could not be found." );
	}
	int fileSize = FileRead_size( filename );
	void* buffer = malloc( fileSize );
	FileRead_read( buffer, fileSize, fileHandle );
	// Run lua script
	string com = static_cast< char* >( buffer );
	com.erase( fileSize );
	if( luaL_dostring( mLua, com.c_str() ) ){
		string mes = lua_tostring( mLua , -1 );
		HALT( mes.c_str() );
	}
	// We are free!
	free( buffer );

	FileRead_close( fileHandle );

}

LuaBindDirectX::~LuaBindDirectX(){
	lua_close( mLua );
}

void LuaBindDirectX::initLua(){
	//call_function< void >( mLua , "Init" );
	LuaCurrentState::instance()->setState( mLua );
    lua_getglobal(mLua, "Init");
    //add(x, y)を呼び出す 引数2個，戻り値1個
    if(lua_pcall(mLua, 0, 0, 0) != 0) {
		string mes = lua_tostring( mLua , -1 );
		HALT( mes.c_str() );
    }
}

void LuaBindDirectX::doLuaLoop(){
	// debug時のみにして
	if( Input::Keyboard::isKeyPressed( KEY_INPUT_F5 ) ){
		reloadScript();
	}
	LuaCurrentState::instance()->setState( mLua );
	lua_getglobal(mLua, "Loop");
	Object::ObjectManager::instance()->update();
	LuaConstantChecker::instance()->check();
    //add(x, y)を呼び出す 引数2個，戻り値1個
    if(lua_pcall(mLua, 0, 0, 0) != 0) {
		string mes = lua_tostring( mLua , -1 );
		HALT( mes.c_str() );
    }
}

void LuaBindDirectX::reloadScript(){
	// Load lua script file
	initLua();
	int fileHandle = FileRead_open( mFilename.c_str() );
	if( fileHandle == 0 ){
		HALT( "Script could not be found." );
	}
	int fileSize = FileRead_size( mFilename.c_str() );
	void* buffer = malloc( fileSize );
	FileRead_read( buffer, fileSize, fileHandle );
	// Run lua script
	string com = static_cast< char* >( buffer );
	com.erase( fileSize );
	if( luaL_dostring( mLua, com.c_str() ) ){
		string mes = lua_tostring( mLua , -1 );
		HALT( mes.c_str() );
	}
	// We are free!
	free( buffer );

	FileRead_close( fileHandle );
}

void moveScene(const char *filename){
	PlScene::Parent::instance()->setNextScene( filename );
}

void writelnLog(const std::string &str){
	LogWritter::instance()->writeln( str );
}

void writeLog(const std::string &str){
	LogWritter::instance()->write( str );
}

void writeTimeLog(const std::string &str){
	LogWritter::instance()->writeWithTime( str );
}

void setMouseVisible(int flag){
	Input::Mouse::instance()->setVisible( flag );
}

void setFpsInterval(int val){
	Utility::FpsControl::instance()->setInterval( val );
}

void quit(){
	PlScene::Parent::instance()->quit();
}

float getFps(){
	return Utility::FpsControl::instance()->getFps();
}

void setTitle(const char* x){
	// ウインドウタイトルの設定
	SetMainWindowText( x );
}

bool isButtonPressed(int key){
	return Input::JoyPad::instance()->isButtonInputed( key );
}

bool isMouseInputed( int button ){
	return Input::Mouse::instance()->isMouseInputed( button );
}

float deg(float n){
	return n * 180.0f / (float)M_PI;
}

float rad(float n){
	return n * (float)M_PI / 180.0f;
}

float myabs(float f){
	return abs( f );
}

float mymax(float l, float r){
	return max( l , r );
}

float mymin(float l, float r){
	return min( l , r );
}

float mypow(float l, float r){
	return pow( l , r );
}