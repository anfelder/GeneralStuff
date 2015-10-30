Player = {}
Player.__index = Player

function Player.create(chips, name)
	local p = {}
	setmetatable(p, Player)
	p.chips = Player.setChips(chips)
	p.name = Player.setName(name)
	return p
end

function Player.setChips(chips)
	return chips

end

function Player.setName(name)
	return name
end
