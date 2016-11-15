function Shot_Init()
	Img_Shot = Image( "Images\\shot.png" )
	Img_Shot_A = Image(Img_Shot, 0, 0, 7, 16)
	Group_Shot= ObjectGroup()
	Group_Shot:setFunction( "GShot_Update" )
	
end

function Shot_Loop()
	Group_Shot:doFunction()
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

function GShot_Update(e)
	Shot_Update(e)
end