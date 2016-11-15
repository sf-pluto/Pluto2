require("Bullet")

function Enemy_Init()
	Bullet_Init()
end

function Enemy_Loop()
	Bullet_Loop()
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

function Enemy_Dead( e )

	Score = Score + 50
end

function CreateBullet( img , x , y , a , s )
	local buf = Object( img , x , y , a, s )
	buf:setAction( "Bullet_Move" )
	buf:addCircle( x , y , 2 )
	buf:setValue("isGrazed", 0)
	Img_Bullet:draw(330,330)
	Group_Bullet:addObject( buf )
end

function CreateBullet2( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Bullet2_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end
