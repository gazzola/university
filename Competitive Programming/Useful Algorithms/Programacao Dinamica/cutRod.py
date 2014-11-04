import numpy as np
def rod_cutting_with_cost(p, n,c):
    r = [0 for i in range(n+1)]
    s = [0 for i in range(n+1)]
     
    for i in range(n):
        q = -np.inf
        for j in range(i+1):
            if j == i:
                if q < p[j] + r[i-j]:
                    q = p[j] + r[i-j]
                    s[i+1] = j+1
            else:
                if q < p[j] + r[i-j] - c:
                    q = p[j] + r[i-j] - c
                    s[i+1] = j+1
        r[i+1] = q
    return r,s
 
def print_cuts(s,n):
    i = n
    print i-s[i]
    i = s[i]
    while s[i] != i:
        print i-s[i]
        i = s[i]
 
p = [1,5, 8, 9, 10, 17,17,20,24,30]
print rod_cutting_with_cost(p,10,0)
print rod_cutting_with_cost(p,10,1)
print rod_cutting_with_cost(p,10,2)
print rod_cutting_with_cost(p,10,3)