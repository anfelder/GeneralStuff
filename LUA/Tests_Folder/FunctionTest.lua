function add(x, y)
	return x + y
end
--assign a1 and a2 to be 8 and 14
a1 = add(3, 5)
a2 = add(5, 9)
--print a1 and a2 repeatedly while decrementing until a1 = 0
repeat
	print("a1 = " .. a1)
	print("a2 = " .. a2)
	a1 = a1 - 1
	a2 = a2 - 1
until a1 == 0