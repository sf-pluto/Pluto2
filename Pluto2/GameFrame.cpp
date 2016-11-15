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

	// ���O�o�͂𖳌���
	SetOutApplicationLogValidFlag( FALSE );

	PlScene::Parent::instance();
	UserObjectManager::instance();
	Utility::FpsControl::instance();

	LuaBindSystem* lua = LuaBindSystem::instance();
	lua->initalize( "main.lua" );
	lua->setGameFrame( this );
	lua->runScript();

	LogWritter::instance()->writeInfo();
	
	// ����ʂɕ`��
	SetDrawScreen( DX_SCREEN_BACK );
	// 2D��3D�̐e�a�����グ��i�s�v�H�j
	Set2D3DKyouzonFlag( TRUE );
	// ��A�N�e�B�u�̏�Ԃł��������p�����邩
	SetAlwaysRunFlag( TRUE );
	// �o�C���j�A�@�B
	SetDrawMode( DX_DRAWMODE_BILINEAR );
	// �E�C���h�E�̃T�C�Y�ύX���\�ɂ���
	//SetWindowSizeChangeEnableFlag( TRUE );
	// ��A�N�e�B�u���ɂ����s
	SetAlwaysRunFlag( TRUE );
	
	// �I���������ǂ���
	bool ended = false;

	// �G���[���o�Ȃ����胋�[�v
	while( ProcessMessage() == 0 && ended == false ){
		// ���ׂẴL�[�̏�Ԃ��擾
		mKeyInput->getAllKeyState();
		// �}�E�X�̏�Ԃ��擾
		Input::Mouse::instance()->getMouseInput();
		// ���O�t�@�C�����J��
		LogWritter::instance()->open();

		// Esc�L�[������Ă�H
		bool mEscPushed = mKeyInput->isKeyPressed( KEY_INPUT_ESCAPE );
		if( mEscPushed ){
			ended = true;
		}

		ClearDrawScreen(); // ��ʏ���

		if( PlScene::Parent::instance()->update() ) ended = true;

		Utility::FpsControl::instance()->calcFps();

		ScreenCopy(); //����ʕ`��

		LogWritter::instance()->close();

	}

	PlScene::Parent::destroy();

	SAFE_DELETE( lua );

	DxLib_End() ;		// DxLib�I������

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