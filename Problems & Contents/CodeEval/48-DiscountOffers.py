import sys


def isVowel(letter):
	vowels = 'aeiouy'
	if letter.lower() in vowels:
		return True
	return False

def isConsonant(letter):
	consonants = 'bcdfghjklmnpqrstvwxz'
	if letter.lower() in consonants:
		return True
	return False 


def isNumber(letter):
	numbers = '0123456789'
	if letter in numbers:
		return True
	return False



def gcd(a, b):
	while(a != 0):
		a, b = b%a, a
	return b


def countLetters(string):
	count = 0

	for l in string:
		if isVowel(l) or isConsonant(l) or isNumber(l):
			count += 1
	return count




def main():

	for line in sys.stdin:
		
		if ";" in line:
			line = line.split(";")
			costumers = line[0].split(",")
			products = line[1].split(",")

			greatest = 0

			for prod in products:

				prod = prod.strip()
				sizep = countLetters(prod)

				greatestC = {}
				for costum in costumers:
					greatestC[costum] = 0

				for costum in costumers:

					count = 0
					if(sizep % 2 == 0):
						for l in costum:
							if isVowel(l):
								count += 1
						count *= 1.5
					else:
						for l in costum:
							if isConsonant(l):
								count += 1

					sizec = countLetters(costum)
					if(gcd(sizep, sizec) > 1):
						count *= 1.5

					greatestC[costum] = max(greatestC[costum], count)



			greatest = sum(greatestC.values())




			print("%.2f" % greatest)





main()