require("Player")
require("EnemyManager")

function Init()
	Img_Obs = Image( "Images\\obs.bmp" )
	Img_SystemFrame = Image( "Images\\system_frame.png" )

	Player_Init()
	EnemyManager_Init()

	Graze = 1500
	Score = 0

	--CreateEnemy( Img_Obs , 400 , 300 )
	CreateEnemyStar( Img_Obs , 520 , 360 )
	--CreateEnemyResju( Img_Obs , 520 , 360 )

	collectgarbage ( "setstepmul" , 800 )
end

function Loop()
	--if Obj_Player:frame() % 150 == 0 then
	--	CreateEnemy( Img_Obs , 200 , 30 )
	--end
	Player_Loop()
	EnemyManager_Loop()

	t = Timer()
	--writelnLog( tostring( Group_Bullet:count() ) .. " bullets took " .. string.sub( tostring( t:elapsed() ) , 1 ,5 ) .. "s." )
	drawString(540, 20, tostring(Graze / 300),  BLUE, TRUE)
	if isKeyPressed( KEY_Z ) then
		Graze = Graze - 5
	end

	Img_SystemFrame:draw(0, 0)

	drawString(640, 20, tostring(Score),  BLUE, TRUE)
	setTitle( string.sub( tostring( getFps() ) , 1 , 5 ) )
end




