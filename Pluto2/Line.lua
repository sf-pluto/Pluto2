function Init()
	line = Line( Point2D( 50 , 240 ) , Point2D( 450 , 240 ) )
	line:setColor( GREEN )
	image = Image( "Images\\test.png" )
	obsimg = Image( "Images\\obs.bmp" )
	objgr = ObjectGroup()
	objgr:addObject( createObject( image , 50 , 300 ) )
	objgr:addObject( createObject2( image , 50 , 350 ) )
	objgr:setFunction( "objgr_func" )
	obsgr = ObjectGroup()
	obsgr:addObject( createObstruct( obsimg , 110 , 320 ) )
	obsgr:setFunction( "obsgr_func" )
	obj = Script( "obj.lua" )
end
function Loop()
	if isKeyPressed( KEY_Z ) then
		line:draw()
	end
	image:draw( 230 , 440 )
	objgr:doFunction()
	obsgr:doFunction()
	obj:update()
	setTitle( string.sub( tostring( getFps() ) , 1 , 5 ) )
end

function createObject( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "obj_move" )
	buf:addHitArea( Circle( x , y , 16 ) )
	return buf
end

function createObject2( img , x , y )
	local buf = Object( img , x , y )
	buf:setAction( "obj2_move" )
	return buf
end

function createObstruct( img , x , y )
	local buf = Object( img , x , y )
	buf:addHitArea( Circle( x , y , 32 ) )
	return buf
end

function obj_move( e )
	e:move( math.cos( e:frame() * math.pi / 24 ) * 3 , math.sin( e:frame() * math.pi / 24 ) * 3 )
end

function obj2_move( e )
	e:move( math.sin( e:frame() * math.pi / 24 ) * 3  , math.sin( e:frame() * math.pi / 24 ) * 3 )
	e:move( e:frame() * 0.014 , 0 )
end

function objgr_func( e )
	e:doAction()
	if not e:isHit( obsgr ) then
		e:draw()
	end
end

function obsgr_func( e )
	e:draw()
end

function Object:__finalize()
    -- called when the an object is collected
end
