require("Enemy")
require("EnemyStar")
require("EnemyResju")

function EnemyManager_Init()
	Group_Enemy = ObjectGroup()
	Group_Enemy:setFunction( "GEnemy_Update" )
	Enemy_Init()
	EnemyStar_Init()
end

function EnemyManager_Loop()
	Group_Enemy:doFunction()
	Enemy_Loop()
end

function GEnemy_Update( e )
	e:doAction()
	e:draw()
end


function CreateEnemy( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "Enemy_Move" )
	buf:setWhenDied( "Enemy_Dead" )
	buf:addCircle( x , y , 32 )
	buf:setHP(50)
	Group_Enemy:addObject( buf )
end

function CreateEnemyStar( img , x , y )
	local buf = Object( img , x , y , -4.0/5.0*PI  , 5 )
	buf:setAction( "Enemy_Star_Move" )
	buf:setVisible( false )
	Group_Enemy:addObject( buf )
end

function CreateEnemyResju( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "EnemyResju_Move" )
	buf:addCircle( x , y , 32 )
	Group_Enemy:addObject( buf )
end
