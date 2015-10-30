--local card = require("Card")
--card.initCards()
local player = require("Player")


--[[print("How many Computer players would you like to play with?")
num_players = io.read("*n")
print("How many chips would you like to start with?")
chips = io.read("*n")
print("What is your name?")
name = io.read()
name = io.read()
i = 0
repeat
	if(i == 0) then
		player.initPlayers(chips, name)
		player.printInfo()
	else
		player.initPlayers(chips, "Computer " .. i)
		player.printInfo()
	end
	i = i + 1
until i == num_players]]
	player.initPlayers(1000, "Andrew")
	player.dealCard()
	player.dealCard()
	player.dealCard()
	player.dealCard()
	player.printCards()
