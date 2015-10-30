Card = {}
Card.__index = Card

function Card.create(id)
	local c = {} --local to this function
	setmetatable(c, Card) --define c as a card object? i.e. Card c = new Card();
	c.name = Card.setName(id)
	c.value = Card.setValue(id)
	c.dealt = Card.setDealt()
	return c
end
function Card.setName(id)
	n = (id % 13) + 1
	if(n == 1) then return "Ace"
	elseif(n == 2) then return "Two"
	elseif(n == 3) then return "Three"
	elseif(n == 4) then return "Four" 
	elseif(n == 5) then return "Five"
	elseif(n == 6) then return "Six"
	elseif(n == 7) then return "Seven"
	elseif(n == 8) then return "Eight"
	elseif(n == 9) then return "Nine"
	elseif(n == 10) then return "Ten"
	elseif(n == 11) then return "Jack"
	elseif(n == 12) then return "Queen"
	elseif(n == 13) then return "King"
	else return "Error in Card.setName()"
	end
end
function Card.setValue(id)
	v = (id % 13) + 1
	if (v > 13) then 
		v = 10
	end 
	return v;
end
function Card.setDealt()
	return false;
end
--[[function Card.initCards()
	i = 0
	c = {}	--becomes a global variable that can be used elsewhere
	repeat
		c[i] = Card.create(i)
		i = i + 1
	until i == 52
	return c
end]]
function Card.init(i)
	c = {}
	c = Card.create(i)
	return c
end
function Card.print(this)
		print("Card: " .. this.name)
		print("Value: " .. this.value)
		print("Dealt: " .. tostring(this.dealt))
end
function Card.dealCard()
	math.randomseed(os.time())
	cardNum = math.random(52) + 1
	if not c[cardNum].dealt then
		c[cardNum].dealt = true;
		c[cardNum].print(cardNum)
		return c[cardNum]
	else Card.dealCard()
	end
end	

return Card

