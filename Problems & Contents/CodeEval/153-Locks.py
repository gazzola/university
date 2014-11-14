'''
' OBS: Identacao tem que ser usando espacos
'''

import sys, math


def qtdPares(n):
    if n % 2 == 0:
        return n/2
    return int((n-1)/2)


def qtdImpares(n):
    if n % 2 == 0:
         return n/2
    return int((n+1)/2)


def qtdParesM3(n):
    return int(math.floor(qtdPares(n)/3.0))


def qtdImparesM3(n):
    return int(math.ceil(qtdPares(n)/3.0))



def method1(n, m):
    
    if m > 1:
        total = 0
        m -= 1

        if m%2 == 0:
            total = qtdImpares(n) + qtdParesM3(n)
        else:
            total = qtdImpares(n) - qtdImparesM3(n) + qtdParesM3(n)


        if m%2 == 0:

            if n%2 == 0 and n%3 != 0:
                total += 1
            elif n%2 != 0 and n%3 == 0:
                total -= 1
            elif n%2 == 0 and n%3 == 0:
                total -= 1
            elif n%2 != 0 and n%3 != 0:
                total -= 1
        else:

            if n%2 == 0 and n%3 != 0:
                total += 1
            elif n%2 != 0 and n%3 == 0:
                total += 1
            elif n%2 == 0 and n%3 == 0:
                total -= 1
            elif n%2 != 0 and n%3 != 0:
                total -= 1

        return int(total)

    return n-1


def method2(n, m):
    
    portas = [False for x in range(n+1)]

    for i in range(m-1):

        for j in range(2, n+1, 2):
            portas[j] = True

        for j in range(3, n+1, 3):
            portas[j] = not portas[j]
    
    portas[-1] = not portas[-1]
    portas = [int(x) for x in portas]
    return n-sum(portas)


test_cases = open(sys.argv[1], 'r')
for test in test_cases:

    cases = test.split(" ")
    n = int(cases[0])
    m = int(cases[1])
    print(method2(n, m))
    print(method1(n, m), end="\n\n")
    

test_cases.close()