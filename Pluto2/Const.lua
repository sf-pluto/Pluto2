class 'Const'

function Const:__init(val)
	self.val = val
end

function Const:__eq(v)
	return self.val
end