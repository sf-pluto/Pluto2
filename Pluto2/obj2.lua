obj2 = {}

function Obj2_Init()
    x = 150
	y = 150
	Obj2Rect = Rectangle( Point2D( x , y ) , Point2D( x + 50 , y + 50 ) )
	Obj2Rect:setColor( WHITE )
	Obj2Rect:setFilled( TRUE )
	rect2 = Rectangle( Point2D( 560 , 420 ) , Point2D( 600 , 460 ) )
	rect2:setColor( RED )
	rect2:setFilled( TRUE )
end

function Obj2_Loop()
	Obj2_Move()
	Obj2Rect:draw()
	if not Obj2Rect:isHit( rect2 ) then
		rect2:draw()
	end
end

function Obj2_Move()

end
