def fib_limit(n):
  a, b = 0, 1
  while n > 0:
    yield b
    a, b = b, a + b
    n -= 1


print (list(fib_limit(48)))


print("\n\n")

def fib_generator():
  a, b = 0, 1
  while True:
    yield b
    a, b = b, a + b


f = fib_generator()
for i in range(48):
	print(next(f), end=", ")

print("\n\n")