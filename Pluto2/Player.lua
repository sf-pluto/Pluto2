require("Shot")

function Player_Init()
	Shot_Init()
	Img_Player = Image( "Images\\Sq_rb.png" )
	
	Obj_Player = Object( Img_Player , 320 , 300 )
	Obj_Player:addCircle( 320, 300 , 1 )
	Obj_Player_Graze  = Object( Img_Player , 320 , 300 )
	Obj_Player_Graze:addCircle( 320, 300 , 20 )
	
	ShotCounter = 0 
	ShotFrame = 0
end

function Player_Loop()
	Player_Update(Obj_Player)
	Player_Graze_Update(Obj_Player_Graze)
	Shot_Loop()
	if not Obj_Player:isHit( Group_Bullet ) then
		Obj_Player:draw()
	end
	
	ShotFrame = ShotFrame + 1
	Obj_Player:drawHitArea()
end

function CreateShot(x, y, r)
	local buf = Object(Img_Shot_A, x, y)
	buf:setSpeed(16)
	buf:setAngle(-PI / 2 + r)
	buf:addCircle(x , y , 2)
	Group_Shot:addObject(buf)
end

function Player_Update( e )
	speed = 5
	add_x = 0
	add_y = 0
 	if isKeyPressed( KEY_LSHIFT ) then
		speed = 2
	end
	if isKeyPressed( KEY_LEFT ) then
		add_x = add_x - 1
	end
	if isKeyPressed( KEY_RIGHT ) then
		add_x = add_x + 1
	end
	if isKeyPressed( KEY_UP ) then
		add_y = add_y - 1
	end
	if isKeyPressed( KEY_DOWN ) then
		add_y = add_y + 1
	end
	if add_x * add_x * add_y * add_y > 0.1 then
		speed = speed * 0.7071067811865475244 
	end
	e:move(add_x * speed, add_y * speed)
	
	-- Create Shot
	if ShotCounter > 3 and Graze > 0 and isKeyPressed( KEY_Z) then
		if isKeyPressed( KEY_LSHIFT ) then
			CreateShot(e:getX() - 3, e:getY() + 5, 0)
			CreateShot(e:getX() + 3, e:getY() + 5, 0)
			CreateShot(e:getX() - 6, e:getY() + 5,  sin(ShotFrame * PI / 48) * PI / 24)
			CreateShot(e:getX() + 6, e:getY() + 5,  -sin(ShotFrame * PI / 48) * PI / 24)
		else
			CreateShot(e:getX() - 3, e:getY() + 5, 0)
			CreateShot(e:getX() + 3, e:getY() + 5, 0)
			CreateShot(e:getX() - 3, e:getY() + 5, PI / 12 )
			CreateShot(e:getX() + 3, e:getY() + 5, -PI / 12 )
		end
		ShotCounter = 0
	else
		ShotCounter = ShotCounter + 1
	end
end

function Player_Graze_Update(e)
	e:moveTo(Obj_Player:getX(), Obj_Player:getY())
	
end