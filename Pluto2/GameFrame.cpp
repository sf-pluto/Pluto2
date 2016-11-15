#include "DxLib.h"
#include "PlUtils.h"

#include "GameFrame.h"

#include "Input/Keyboard.h"
#include "Input/Mouse.h"
#include "Lua/LuaBindSystem.h"
#include "Scene/Parent.h"
#include "Utility/FpsControl.h"
#include "Object/UserObjectManager.h"
#include "LogWritter.h"

namespace {

};


void GameFrame::doGameLoop( int WindowModeFlag ){

	// ログ出力を無効化
	SetOutApplicationLogValidFlag( FALSE );

	PlScene::Parent::instance();
	UserObjectManager::instance();
	Utility::FpsControl::instance();

	LuaBindSystem* lua = LuaBindSystem::instance();
	lua->initalize( "main.lua" );
	lua->setGameFrame( this );
	lua->runScript();

	LogWritter::instance()->writeInfo();
	
	// 裏画面に描画
	SetDrawScreen( DX_SCREEN_BACK );
	// 2Dと3Dの親和性を上げる（不要？）
	Set2D3DKyouzonFlag( TRUE );
	// 非アクティブの状態でも処理を継続するか
	SetAlwaysRunFlag( TRUE );
	// バイリニア法。
	SetDrawMode( DX_DRAWMODE_BILINEAR );
	// ウインドウのサイズ変更を可能にする
	//SetWindowSizeChangeEnableFlag( TRUE );
	// 非アクティブ時にも続行
	SetAlwaysRunFlag( TRUE );
	
	// 終了したかどうか
	bool ended = false;

	// エラーが出ない限りループ
	while( ProcessMessage() == 0 && ended == false ){
		// すべてのキーの状態を取得
		mKeyInput->getAllKeyState();
		// マウスの状態を取得
		Input::Mouse::instance()->getMouseInput();
		// ログファイルを開く
		LogWritter::instance()->open();

		// Escキー押されてる？
		bool mEscPushed = mKeyInput->isKeyPressed( KEY_INPUT_ESCAPE );
		if( mEscPushed ){
			ended = true;
		}

		ClearDrawScreen(); // 画面消去

		if( PlScene::Parent::instance()->update() ) ended = true;

		Utility::FpsControl::instance()->calcFps();

		ScreenCopy(); //裏画面描画

		LogWritter::instance()->close();

	}

	PlScene::Parent::destroy();

	SAFE_DELETE( lua );

	DxLib_End() ;		// DxLib終了処理

}

GameFrame::GameFrame(){
	mKeyInput = new Input::Keyboard();
}

GameFrame::~GameFrame(){
	SAFE_DELETE( mKeyInput );
}

void GameFrame::createScene(const std::string& filename){
	PlScene::Parent::instance()->setScene( filename );
}