#include "Sound.h"
#include "DxLib.h"

namespace Object{

Sound::Sound(const char *filename) : mHandle( LoadSoundMem( filename ) ),
mIsLoop( false ){
}

Sound::~Sound(){
	DeleteSoundMem( mHandle );
}

void Sound::play(){
	if( mIsLoop ) PlaySoundMem( mHandle , DX_PLAYTYPE_LOOP );
	else PlaySoundMem( mHandle , DX_PLAYTYPE_BACK );
}

void Sound::stop(){
	StopSoundMem( mHandle );
}

void Sound::setAsLoop(bool val){
	mIsLoop = val;
}

void Sound::setPanpot(int val){
	SetPanSoundMem( val , mHandle );
}

void Sound::setVolume(int val){
	SetVolumeSoundMem( val , mHandle );
}

void Sound::setFrequency(int val){
	SetFrequencySoundMem( val , mHandle );
}

void Sound::setLoopPosition(int val){
	SetLoopPosSoundMem( val , mHandle );
}

void Sound::setPosition(int val){
	SetSoundCurrentTime( val , mHandle );
}

bool Sound::isPlaying(){
	return CheckSoundMem( mHandle ) == TRUE ? true : false;
}

}