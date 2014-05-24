def fatIter(n)
	fat = 1
	while n > 1
		fat *= n
		n -= 1
	end

	return fat
end

n = ARGV.at(0).to_i
fat = fatIter(n)
puts fat