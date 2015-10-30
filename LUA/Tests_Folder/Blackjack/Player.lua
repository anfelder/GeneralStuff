Player = {}
Player.__index = Player

function Player.create()
	local p = {}
	setmetatable(p, Player)

	return p
end

function Player.setChips()


end

function Player.setName()

end