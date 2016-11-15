#include "DxLib.h"
#include "GameFrame.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	
	GameFrame *gf = new GameFrame();
	// メインループの実行
	gf->doGameLoop( TRUE );
	delete gf;
	
	return 0 ;		// ソフトの終了
}