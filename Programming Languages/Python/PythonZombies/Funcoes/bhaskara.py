import sys, os
from math import sqrt

def bhaskara(a, b, c):
    delta = (b * b) - (4 * a * c)
    print('Delta: %d' %delta)
    if delta < 0:
        # Delta menor que 0, a função não tem raízes
        return 'Delta menor que zero'
    else:
        delta = sqrt(delta)
        r1 = (-b + delta) / (2 * a)
        r2 = (-b - delta) / (2 * a)
        raizes = [r1, r2]
        # Retornando as raízes
        return raizes

a = int(sys.argv[1])
b = int(sys.argv[2])
c = int(sys.argv[3])

print(bhaskara(a,b,c))