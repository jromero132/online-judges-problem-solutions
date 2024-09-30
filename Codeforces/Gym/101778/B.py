# Problem name: Ran and the Lock Code
# Problem link: https://codeforces.com/gym/101778/problem/B
# Submission link: https://codeforces.com/gym/101778/submission/37293443

import math

t = int(input())
while t > 0:
    t = t-1
    s = input().split(' ')
    #print(s[0])
    #print(s[1])
    n = int(s[0])
    a = int(s[1])
    x = (a*n-n)*2
    k = int(math.sqrt(x))
    k = min(k, n)
    while k < n and k*(k+1) <= x:
        k=k+1
    print(k)