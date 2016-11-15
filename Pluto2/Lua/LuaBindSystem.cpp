#include "LuaBindSystem.h"
#include "DxLib.h"
#include "../GameFrame.h"

#include "LuaUtils.h"

using namespace luabind;

int setWindow(int x, int y, int d, int f);
int setTitle( const char* x );
void gCreateScene( const std::string &filename );
void initPluto();


LuaBindSystem::LuaBindSystem(){
	 //Luaを開く
	mLua = lua_open();
}

void LuaBindSystem::initalize(const char *filename){
	 //Luaを開く
    mLua = initLuaBind();
	
    //Luaの標準関数を使用できる状態にする
    luaL_openlibs( mLua );

	setConstant( mLua , "TRUE" , TRUE );
	setConstant( mLua , "FALSE" , FALSE );

	module(mLua) [
		def( "setWindow" , setWindow ),
		def( "setTitle" , setTitle ),
		def( "createScene" , gCreateScene ),
		def( "initPluto" , initPluto )
	];

	if( luaL_dofile( mLua , filename ) ){
	}
}

LuaBindSystem::~LuaBindSystem(){
	lua_close( mLua );
}

int setWindow(int x, int y, int d, int f){
	// 画面解像度とモード

	SetGraphMode( x , y , d );
	// ウインドウかフルスクリーンか
	ChangeWindowMode( f );
	return 0;
}

int setTitle(const char* x){
	// ウインドウタイトルの設定
	SetMainWindowText( x );
	return 0;
}

void gCreateScene( const std::string &filename ){
	LuaBindSystem::instance()->createScene( filename );
}

void LuaBindSystem::createScene(const std::string &filename){
	mGameFrame->createScene( filename );
}

void LuaBindSystem::setGameFrame(GameFrame* ptr){
	mGameFrame = ptr;
}

void LuaBindSystem::runScript(){
	call_function< void >( mLua , "Main" );
}

void initPluto(){
	// DxLib初期化処理
	if( DxLib_Init() == -1 ){
		 return;	// エラーが起きたら直ちに終了
	}

}
