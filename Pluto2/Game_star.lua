function Init()
	Img_Player = Image( "Images\\Sq_rb.png" )
	Img_Obs = Image( "Images\\obs.bmp" )
	Img_Bullet = Image( "Images\\bullet.png" )
	Obj_Player = Object( Img_Player , 320 , 300 )
	Obj_Player:setAction( "Player_Move" )
	Obj_Player:addHitArea( Rectangle( 314 , 285 , 326 , 315 ) )
	Group_Enemy = ObjectGroup()
	Group_Enemy:setFunction( "GEnemy_Update" )
	Group_Bullet = ObjectGroup()
	Group_Bullet:setFunction( "GBullet_Update" )
	--CreateEnemy( Img_Obs , 320 , 240 )
	CreateEnemyStar( Img_Obs , 160 , 220 )
	collectgarbage ( "setstepmul" , 800 )
end

function Loop()
	--if Obj_Player:frame() % 150 == 0 then
	--	CreateEnemy( Img_Obs , 200 , 30 )
	--end
	Group_Enemy:doFunction()
	t = Timer()
	Group_Bullet:doFunction()
	writelnLog( tostring( Group_Bullet:count() ) .. " bullets took " .. string.sub( tostring( t:elapsed() ) , 1 ,5 ) .. "s." )
	Obj_Player:doAction()
	if not Obj_Player:isHit( Group_Bullet ) then
		Obj_Player:draw()
	end
	if isKeyPressed( KEY_W ) then
		moveScene("Game_2.lua")
	end
	setTitle( string.sub( tostring( getFps() ) , 1 , 5 ) )
	--writeLog( string.sub( tostring( getFps() ) , 1 , 5 ) )
end

function Player_Move( e )
	if isKeyPressed( KEY_LEFT ) then
		e:move( -4 , 0 )
	end
	if isKeyPressed( KEY_RIGHT ) then
		e:move( 4 , 0 )
	end
	if isKeyPressed( KEY_UP ) then
		e:move( 0 , -4 )
	end
	if isKeyPressed( KEY_DOWN ) then
		e:move( 0 , 4 )
	end
end

function Enemy_Move( e )
	--e:move( cos( e:frame() * PI / 24 ) * 3  , sin( e:frame() * PI / 24 ) * 3 )
	--e:move( 4 , 0 )
	w = 100
	if e:frame() < 55 then
	--	for i=1,w do
	--		CreateBullet( Img_Bullet , e:getX() , e:getY() , sin( PI * e:frame() / 720 ) * PI * 4 + PI * 2 * i / w , 2 + sin(e:frame()/6*PI/24) )
	--	end
		--CreateBullet2( Img_Bullet , e:getX() + 12 , e:getY() )
		--for i=1,w do
			CreateBullet( Img_Bullet ,150*cos(2*i*PI/w)+320 , -150*sin(2*2*i*PI/w-PI/4)+240 ,0 ,1 )
		--end
	end
	
end

function Enemy_Star_Move( e )
	if e:frame() % (13 * 5) == 0 then
		e:addAngle( 4.0/5.0*PI )
	end
	e:move()
	if e:frame() < 65 * 5 then
		if e:frame() % 5 == 0 then
			CreateBulletStar( Img_Bullet ,e:getX() ,e:getY(),0 , e:frame() )
		end
	else
		e:die()
	end
end

function Bullet_Move( e )
	e:move()
	e:setAngle( atan2( -(e:getX()-320)/160 , 1)  )
	if e:isOutOfWindow() or e:isClicked() then
		e:die()
	end
end

function Bullet2_Move( e )
	if e:isOutOfWindow() then
		e:die()
	end
end

function BulletStar_Move( e )
	if e:frame() >= 400-e:speed() then
		for i=1,5 do
			CreateBulletStar2( Img_Bullet ,e:getX() ,e:getY(), (i-1)*2*PI/5-PI/2 , 2.0, e:frame()-75)
		end
		e:die()
	end
end

function BulletStar2_Move( e )
	if e:frame() == 80 then
		e:setSpeed(0)
	end
	if e:frame() == 140 + ( e:getHP() % 65 ) * 1 then
		e:setAngle( ( e:getHP() / 65 ) * PI * 2 / 5 )
		e:setSpeed(2)
	end
	e:move()
end

function CreateEnemy( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Enemy_Move" )
	buf:addCircle( x , y , 32 )
	Group_Enemy:addObject( buf )
end

function CreateEnemyStar( img , x , y )
	local buf = Object( img , x , y , -4.0/5.0*PI  , 5 )
	buf:setAction( "Enemy_Star_Move" )
	buf:setVisible( false )
	Group_Enemy:addObject( buf )
end

function CreateBullet( img , x , y , a , s )
	local buf = Object( img , x , y , a, s )
	buf:setAction( "Bullet2_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end

function CreateBulletStar( img , x , y , a , s )
	local buf = Object( img , x , y , a, s )
	buf:setAction( "BulletStar_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end

function CreateBulletStar2( img , x , y , a , s , h)
	local buf = Object( img , x , y , a, s )
	buf:setAction( "BulletStar2_Move" )
	buf:setHP( h )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end

function CreateBullet2( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Bullet2_Move" )
	buf:addHitArea( Circle( x , y , 4 ) )
	Group_Bullet:addObject( buf )
end

function GEnemy_Update( e )
	e:doAction()
	e:draw()
end

function GBullet_Update( e )
	e:doAction()
	e:draw()
end
