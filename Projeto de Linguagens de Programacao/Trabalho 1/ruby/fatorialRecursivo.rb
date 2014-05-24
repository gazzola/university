def fatRec(n)
	if n < 2
		return 1
	else
		return n * fatRec(n-1)
	end
end

n = ARGV.at(0).to_i
fat = fatRec(n)
puts fat