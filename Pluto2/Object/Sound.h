#ifndef INCLUDED_OBJECT_SOUND_H
#define INCLUDED_OBJECT_SOUND_H

namespace Object{

class Sound{
public:
	Sound( const char* filename );
	~Sound();

	void play();
	void stop();
	void setAsLoop( bool val );
	void setPanpot( int val );
	void setVolume( int val );
	void setFrequency( int val );
	void setLoopPosition( int val );
	void setPosition( int val );
	bool isPlaying();
private:
	int mHandle;
	bool mIsLoop;
};

}

#endif //#ifndef INCLUDED_OBJECT_SOUND_H