function Init()
	Img_Player = Image( "Images\\Sq_rb.png" )
	Img_Obs = Image( "Images\\obs.bmp" )
	Img_Bullet = Image( "Images\\bullet.png" )
	Img_Shot = Image( "Images\\bullet.png" )
	Img_SystemFrame = Image( "Images\\system_frame.png" )
	Img_Shot = Image( "Images\\shot.png" )
	Img_Shot_A = Image(Img_Shot, 0, 0, 7, 16)
	
	Obj_Player = Object( Img_Player , 320 , 300 )
	Obj_Player:setAction( "Player_Update" )
	Obj_Player:addRectangle( 314 , 285 , 326, 315 )
	
	Group_Enemy = ObjectGroup()
	Group_Enemy:setFunction( "GEnemy_Update" )
	Group_Bullet = ObjectGroup()
	Group_Bullet:setFunction( "GBullet_Update" )
	Group_Shot= ObjectGroup()
	Group_Shot:setFunction( "GShot_Update" )
	
	ShotCounter = 0 
	
	--CreateEnemy( Img_Obs , 320 , 240 )
	
	collectgarbage ( "setstepmul" , 800 )
end

function Loop()
--	profiler:start("plog")
	--if Obj_Player:frame() % 150 == 0 then
	--	CreateEnemy( Img_Obs , 200 , 30 )
	--end
	Group_Enemy:doFunction()
	t = Timer()
	Group_Bullet:doFunction()
	Group_Shot:doFunction()
	writelnLog( tostring( Group_Bullet:count() ) .. " bullets took " .. string.sub( tostring( t:elapsed() ) , 1 ,5 ) .. "s." )
	Obj_Player:doAction()
	if not Obj_Player:isHit( Group_Bullet ) then
		Obj_Player:draw()
	end
	Obj_Player:drawHitArea()
	
	Img_SystemFrame:draw(0, 0)
	setTitle( string.sub( tostring( getFps() ) , 1 , 5 ) )
--	profiler:stop()
	--writeTimeLog( "-- Player ---------\n" .. Obj_Player:toString() )
end

function Player_Update( e )
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
	
	if isKeyPressed( KEY_Z ) and ShotCounter > 3 then
		CreateShot(e:getX() - 3, e:getY() + 5, 0)
		CreateShot(e:getX() + 3, e:getY() + 5, 0)
		CreateShot(e:getX() - 3, e:getY() + 5, PI / 12)
		CreateShot(e:getX() + 3, e:getY() + 5, -PI / 12)
		ShotCounter = 0
	else
		ShotCounter = ShotCounter + 1
	end
end

function Enemy_Move( e )
	--e:move( cos( e:frame() * PI / 24 ) * 3  , sin( e:frame() * PI / 24 ) * 3 )
	--e:move( 4 , 0 )
	w = 7
	if e:frame() % 5 == 0 then
		for i=1,w do
			CreateBullet( Img_Bullet , e:getX() , e:getY() , sin( PI * e:frame() / 720 ) * PI * 4 + PI * 2 * i / w , 2 + sin(e:frame()/6*PI/24) )
		end
		--CreateBullet2( Img_Bullet , e:getX() , e:getY() )
	end
end

function Bullet_Move( e )
	e:addSpeed( -0.02 )
	e:move()
	if e:isOutOfWindow()  then
		e:die()
	end
	--if e:frame() > 20 then
	--	e:setSpeed(0)
	--end
end

function Bullet2_Move(e)
	e:move(0, 0.5)
end

function CreateShot(x, y, r)
	local buf = Object(Img_Shot_A, x, y)
	buf:setSpeed(16)
	buf:setAngle(-PI / 2 + r)
	buf:addCircle(x , y , 2)
	Group_Shot:addObject(buf)
end

function Shot_Update(e)
	e:move()
	if e:isOutOfWindow() then
		e:die()
	end
	
	if e:isHit(Group_Enemy) then
		e:getHitObject():addHP(-2)
		e:die()
	else
		e:drawRotate()
	end
end

function CreateEnemy( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Enemy_Move" )
	buf:addCircle( x , y , 32 )
	buf:setHP(50)
	Group_Enemy:addObject( buf )
end

function CreateBullet( img , x , y , a , s )
	local buf = Object( img , x , y , a, s )
	buf:setAction( "Bullet_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end

function CreateBullet2( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Bullet2_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end

function GShot_Update(e)
	Shot_Update(e)
end

function GEnemy_Update( e )
	e:doAction()
	e:draw()
end

function GBullet_Update( e )
	Bullet_Move(e)
	e:draw()
end
