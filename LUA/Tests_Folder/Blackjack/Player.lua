Player = {}
Player.__index = Player
local card = require("Card")
--card.initCards()
card_array = {}
current_card = 0
function initCard()
	local i = 0
	repeat
		card_array[i] = card.init(i)
		i = i + 1
	until i == 52
	return 0
end
initCard()
function Player.create(chips, name)
	local p = {}
	setmetatable(p, Player)
	p.cards = {}
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
function Player.initPlayers(chips, name)
	p = {} --global version of p to be used everywhere
	p = Player.create(chips, name)
	p.cards = {}
	return p
end
function Player.printInfo()
	print("Name: " .. p.name)
	print("Chips: " .. p.chips)

end
function Player.dealCard()
	--p.cards[current_card] = card.dealCard()
	math.randomseed(os.time())
	cardNum = math.random(52) + 1
	if not card_array[cardNum].dealt then
		card_array[cardNum].dealt = true;
		p.cards[current_card] = card_array[cardNum]
		current_card = current_card + 1
	else Player.dealCard()
	end
end
function Player.printCards()
	local x = 0 
	for _ in pairs(p.cards) do 
		--p.cards[x].print(self)
		card.print(p.cards[x]) --calls card.print method and prints p.cards[x]
		x = x + 1
	end
end
function printCard()
	print("Card: " .. c.name)
	print("Value: " .. c.value)
	print("Dealt: " .. tostring(c.dealt))
end
return Player