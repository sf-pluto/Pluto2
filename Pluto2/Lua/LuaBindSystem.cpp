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
	 //Lua���J��
	mLua = lua_open();
}

void LuaBindSystem::initalize(const char *filename){
	 //Lua���J��
    mLua = initLuaBind();
	
    //Lua�̕W���֐����g�p�ł����Ԃɂ���
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
	// ��ʉ𑜓x�ƃ��[�h

	SetGraphMode( x , y , d );
	// �E�C���h�E���t���X�N���[����
	ChangeWindowMode( f );
	return 0;
}

int setTitle(const char* x){
	// �E�C���h�E�^�C�g���̐ݒ�
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
	// DxLib����������
	if( DxLib_Init() == -1 ){
		 return;	// �G���[���N�����璼���ɏI��
	}

}
