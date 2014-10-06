'''
' OBS: Identacao tem que ser usando espacos
'''

import sys

def verifica(msg):

    abre, fecha, hap, sad = 0, 0, 0, 0

    for i, c in enumerate(msg):
        if c == '(':
            abre += 1
            if msg[i-1] == ':':
                sad += 1
        elif c == ')':
            fecha += 1
            if msg[i-1] == ':':
                hap += 1

            if fecha-hap > abre:
                return False

    if abre-sad <= fecha and fecha <= abre:
        return True
    elif fecha-hap <= abre and abre <= fecha:
        return True

    return False


test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    if(verifica(test)):
        print("YES")
    else:
        print("NO")

test_cases.close()