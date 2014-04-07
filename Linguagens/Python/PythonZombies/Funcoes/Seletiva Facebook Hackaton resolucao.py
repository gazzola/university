def hack1(n, k):
  def f(s):
    return s.count('1')

  binarios = []
  for x in range(2**n):
    binarios.append(bin(x))

  binarios.sort(key=f, reverse = True)
  return binarios[k-1]

def hack(n, k):
  return sorted([bin(x) for x in range(2**n)],
                key=lambda s: s.count('1'),
                reverse = True)[k-1]
  
print(hack(3, 5))