'''
' OBS: Identacao tem que ser usando espacos
'''

import sys




def isJolly(n, cases):
    
    visits = [False for x in range(n)]
    total = 0

    for i in range(2, n+1):

        dif = abs(int(cases[i])-int(cases[i-1]))

        #print(dif, k)
        if(dif <= 0 or dif >= n):
            return False
        elif(visits[dif]):
            return False

        if(not visits[dif]):
          visits[dif] = True
          total += 1

    return (total == n-1)



test_cases = open(sys.argv[1], 'r')
for test in test_cases:

    cases = test.split(" ")
    n = int(cases[0])
    if(isJolly(n, cases)):
        print("Jolly")
    else:
        print("Not jolly")


test_cases.close()