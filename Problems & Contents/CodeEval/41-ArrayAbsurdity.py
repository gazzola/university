'''
' OBS: Identacao tem que ser usando espacos
'''

import sys


def total(n):
    return (n*n - 3*n + 2)/2


def method1(cases, n):
    t = total(n)
    s = 0
    for x in cases.split(","):
        s += int(x)
    return int(s-t)

def method2(cases, n):
    a = 0
    for i, x in enumerate(cases.split(",")):
        a = a ^ (int(x)+1) ^ i
    return (a-1)

test_cases = open(sys.argv[1], 'r')
for test in test_cases:

    cases = test.split(";")
    n = int(cases[0])
    print(method2(cases[1], n))
    

test_cases.close()