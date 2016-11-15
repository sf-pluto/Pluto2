require ("Bullet")

function EnemyResju_Init()
end

function EnemyResju_Loop()
end

function EnemyResju_Move( e )
	w = 100
	if e:frame() == 12 then
		for i=1,w do
			CreateBulletResju(Img_Bullet ,150*cos(2*i*PI/w)+320 , -150*sin(2*2*i*PI/w-PI/4)+240 ,0 ,1 )
		end
	end

end


function EnemyResju_Dead( e )

	Score = Score + 50
end

function CreateBulletResju( img , x , y , a , s )
	local buf = Object( img , x , y , a, s )
	buf:setAction( "BulletResju_Move" )
	buf:addCircle( x , y , 4 )
	Group_Bullet:addObject( buf )
end
