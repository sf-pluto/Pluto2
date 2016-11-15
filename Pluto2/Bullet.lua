function Bullet_Init()
	Img_Bullet = Image( "Images\\bullet.png" )
	Group_Bullet = ObjectGroup()
	Group_Bullet:setFunction( "GBullet_Update" )
end

function Bullet_Loop()
	Group_Bullet:doFunction()
end

function Bullet_Move( e )
	e:addSpeed( -0.02 )
	e:move()
	if e:getValue("isGrazed") == 0 and e:isHit(Obj_Player_Graze) then
		e:setValue("isGrazed", 1)
		Graze = Graze + 12
	end
	if e:isOutOfWindow()  then
		e:die()
	end
end

function Bullet2_Move(e)
	e:move(0, 0.5)
end

function GBullet_Update( e )
	e:doAction()
	e:draw()
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

function BulletResju_Move(e)
	if e:isOutOfWindow() then
		e:die()
	end
end
