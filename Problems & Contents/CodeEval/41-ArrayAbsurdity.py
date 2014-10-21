'''
' OBS: Identacao tem que ser usando espacos
'''

import sys


def total(n):
    return (n*n - 3*n + 2)/2

test_cases = open(sys.argv[1], 'r')
for test in test_cases:

    cases = test.split(";")
    n = int(cases[0])
    t = total(n)
    s = 0
    for x in cases[1].split(","):
        #print(x)
        s += int(x)
    print(int(s-t))

test_cases.close()