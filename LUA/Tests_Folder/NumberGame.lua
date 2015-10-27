print("This is a guess the number game.\nChoose a maximum number:")

max = io.read("*n")
math.randomseed(os.time())
num = math.random(max)
--print(num)
print("Enter a guess between 0 and " .. max .. ": ")
repeat
	guess = io.read("*n")
	if(guess > max) then guess = max
	elseif (guess < 0) then guess = 0
	end

	if(guess > num) then
		print("You guessed too high, try again: ")
	elseif(guess < num) then 
		print("You guessed too low, try again: ")
	end
until guess == num

print("You have correctly guessed the number!")