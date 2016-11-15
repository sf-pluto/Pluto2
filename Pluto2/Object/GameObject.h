#ifndef INCLUDED_OBJECT_GAMEOBJECT_H
#define INCLUDED_OBJECT_GAMEOBJECT_H

#include <string>
#include <map>

using namespace std;

class Image;
struct lua_State;

namespace Object{

class HitArea;
class Figure;
class GameObjectGroup;
class ObjectObserver;

class GameObject{
public:
	GameObject();
	GameObject( const Image& image , float x , float y );
	GameObject( const Image& image , float x , float y , float angle );
	GameObject( const Image& image , float x , float y , float angle , float speed );
	GameObject( const GameObject& other );
	~GameObject();

	GameObject& operator =( const GameObject& other );

	void doAction();
	void move();
	void move( float x , float y );
	void moveTo( float x , float y );
	void draw();
	void drawRotate();
	void drawHitArea();
	void die();
	void destroyHitArea();
	string toString();
	// add
	void addHitArea( Figure* area );
	void addCircle( float x , float y , float r );
	void addRectangle( float x1 , float y1 , float x2 , float y2 );
	void addRotatedRect( float cx , float cy , float width , float height , float angle );
	void addHP( int val );
	void addSpeed( float val );
	void addAngle( float val );
	void addFrame();
	void addVelocity( float x , float y );
	// set
	void setAction( const string& str );
	void setWhenDied( const string& str );
	void setAngle( float val );
	void setSpeed( float val );
	void setVelocity( float x , float y );
	void setVisible( bool val );
	void setHP( int val );
	void setValue( const std::string& str, int val );
	// get
	int frame() const;
	int getHP() const;
	int getValue( const string& str );
	float getX() const;
	float getY() const;
	float getVX() const;
	float getVY() const;
	float angle() const;
	float speed() const;
	GameObject& getHitObject() const;
	// is
	bool isHit( const GameObject& other );
	bool isHit( const GameObjectGroup& group );
	bool isHit( const GameObjectGroup& group , GameObject& obj );
	bool isClicked();
	bool isOutOfWindow();
	bool isDead();
	const Image& getImage();
private:
	const Image& mImage;
	HitArea* mHitArea;
	lua_State* mState;
	ObjectObserver* mObserver;
	GameObject* mHitObject; 
	string mAction;
	string mWhenDied;
	map<string, int> mValue;
	int mFrame;
	int mHP;
	float mX;
	float mY;
	float mVX;
	float mVY;
	float mAngle;
	float mSpeed;
	bool mIsDead;
	bool mVisible;
};

}

#endif //#ifndef INCLUDED_OBJECT_GAMEOBJECT_H