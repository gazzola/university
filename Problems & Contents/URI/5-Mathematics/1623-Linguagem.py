# import sys

# retirado de: 
# http://en.literateprograms.org/Factorials_with_prime_factorization_%28Python%29

def multiplicity(n, p):
	"""Return the power of the prime number p in the
	factorization of n!"""
	if p > n: return 0
	if p > n//2: return 1
	q, m = n, 0
	while q >= p:
		q //= p
		m += q
	return m


def primes(n):
	"""Generate a list of the prime numbers [2, 3, ... m] where
	m is the largest prime <= n."""
	n = n + 1
	sieve = range(n)
	sieve[:2] = [0, 0]
	for i in xrange(2, int(n**0.5)+1):
		if sieve[i]:
			for j in xrange(i**2, n, i):
				sieve[j] = 0
	# Filter out the composites, which have been replaced by 0's
	return [p for p in sieve if p]


def powproduct(ns):
	"""Compute the explicit value of a factored integer
	given as a list of (base, exponent) pairs."""
	if not ns:
		return 1
	units = 1
	multi = []
	for base, exp in ns:
		if exp == 0:
			continue
		elif exp == 1:
			units *= base
		else:
			if exp % 2:
				units *= base
			multi.append((base, exp//2))
	return units * powproduct(multi)**2


prs = primes(100001)

def factorial(n):
	return powproduct((p, multiplicity(n, p)) for p in prs)


while True:

	n, q = map(int, raw_input().split())
	if n == q and q == 0:
		break

	t = int(raw_input())
	x = factorial(n-q+1)
	if x > t:
		print "descartado"
	else:
		print x

