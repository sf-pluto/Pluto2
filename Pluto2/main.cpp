#include "DxLib.h"
#include "GameFrame.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	
	GameFrame *gf = new GameFrame();
	// ���C�����[�v�̎��s
	gf->doGameLoop( TRUE );
	delete gf;
	
	return 0 ;		// �\�t�g�̏I��
}