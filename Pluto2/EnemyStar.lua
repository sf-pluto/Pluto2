require ("Bullet")

function EnemyStar_Init()
end

function EnemyStar_Loop()
end

function Enemy_Star_Move( e )
	if e:frame() % (13 * 5) == 0 then
		e:addAngle( 4.0/5.0*PI )
	end
	e:move()
	if e:frame() < 65 * 5 + 1  then
		if e:frame() % 5 == 0 then
			CreateBulletStar( Img_Bullet ,e:getX() ,e:getY(),0 , e:frame() )
		end
	else
		e:die()
	end
end


function Enemy_Star_Dead( e )

	Score = Score + 50
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
