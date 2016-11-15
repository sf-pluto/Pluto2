require ( "obj2" )

function Init()
    x = 50
	y = 50
	anim = Animation( "Images/anim.bmp" , 4 , 4 , 1 , 64 , 64 )
	anim:setInterval( 20 )
	rect = Rectangle( Point2D( x , y ) , Point2D( x + 50 , y + 50 ) )
	rect:setColor( BLUE )
	rect:setFilled( TRUE )
	circle = Circle( Point2D( 240 , 80 ) , 100 )
	circle:setColor( BLUE )
	circle:setFilled( TRUE )
	--obj = Object( "obj2.lua" )
	Obj2_Init()
end

function Loop()
	Move()
	anim:swing( 20 , 20 )
	rect:draw()
	if not rect:isHit( rect2 ) then
		circle:draw()
	end
	Obj2_Loop()
end

function Move()
	if isKeyPressed( KEY_LEFT ) then
		rect:move( -4 , 0 )
	end
	if isKeyPressed( KEY_RIGHT ) then
		rect:move( 4 , 0 )
	end
	if isKeyPressed( KEY_UP ) then
		rect:move( 0 , -4 )
	end
	if isKeyPressed( KEY_DOWN ) then
		rect:move( 0 , 4 )
	end

end
