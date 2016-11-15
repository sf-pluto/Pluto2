function Init()
	Img_Block = Image( "Images2\\block.png" )
	Img_Player = Image( "Images2\\bar.png" )
	Img_Ball = Image( "Images2\\ball.png" )
	Obj_Player = Object( Img_Player , 320 , 420 )
	Obj_Player:setAction( "Player_Move" )
	Obj_Player:addHitArea( Rectangle( 280 , 418 , 360 , 442 ) )
	Group_Block = ObjectGroup()
	Group_Block:setFunction( "GBlock_Update" )
	Group_Ball= ObjectGroup()
	Group_Ball:setFunction( "GBall_Update" )
	CreateBall( 320 , 120 )
	Player_vx = 0.0
	for  i = 1 ,14 , 1 do
		for j = 1 , 4 , 1 do
			CreateBlock( i*40+20 , j*16 + 8 )
		end
	end
	collectgarbage ( "setstepmul" , 800 )
end

function Loop()
	Group_Block:doFunction()
	Group_Ball:doFunction()
	Obj_Player:doAction()
	Obj_Player:draw()
	if isKeyPressed( KEY_Q ) then
		moveScene("Game.lua")
	end
	setTitle( string.sub( tostring( getFps() ) , 1 , 5 ) )
end

function Player_Move( e )
	if isKeyPressed( KEY_LEFT ) then
		Player_vx = Player_vx - 0.15
		e:move( Player_vx , 0 )
	elseif isKeyPressed( KEY_RIGHT ) then
		Player_vx = Player_vx + 0.15
		e:move( Player_vx , 0 )
	else
		Player_vx = 0.0
	end
end

function Ball_Move( e )
	for  i = 1 , 5 , 1 do
		if e:getX() < 3 or e:getX() > 637 then
			e:setVelocity(-e:getVX(), e:getVY()) 
		elseif e:getY() < 3 then
			e:setVelocity(e:getVX(), -e:getVY()) 
		end
		if e:isHit( Obj_Player ) then
			e:setVelocity(e:getVX() + ( e:getX() - Obj_Player:getX() ) / 40, -e:getVY()) 
			writelnLog( "The ball hit with player in (" .. tostring( e:getX() ) .. "," .. tostring( e:getY() ).. ")" )
		end
		e:move()
	end
	--e:setVelocity(e:getVX() + sin( e:frame() * PI / 60 ) * 0.1, e:getVY() + cos( e:frame() * PI / 60 ) * 0.01 ) 
	--writelnLog( "Ball(" .. tostring( Ball_vx ) .. "," .. tostring( Ball_vy ).. ")" )
end


function Block_Move( e )
	if e:isHit( Group_Ball ) then
		writelnLog( "The ball destroyed a block! (" .. tostring( e:getX() ) .. "," .. tostring( e:getY() ).. ")" )
		e:die()
	end
end

function CreateBlock( x , y )
	local buf = Object( Img_Block , x , y  )
	buf:setAction( "Block_Move" )
	buf:addRectangle( x -20, y-8 , x+20, y+8 )
	Group_Block:addObject( buf )
end

function CreateBall( x , y )
	local buf = Object( Img_Ball , x , y  )
	buf:setAction( "Ball_Move" )
	buf:addCircle( x, y , 3 )
	buf:setVelocity( 0.0 , 2.0 )
	Group_Ball:addObject( buf )
end


function GBlock_Update( e )
	e:doAction()
	e:draw()
	e:drawHitArea()
end

function GBall_Update( e )
	e:doAction()
	e:draw()
	e:drawHitArea()
end
