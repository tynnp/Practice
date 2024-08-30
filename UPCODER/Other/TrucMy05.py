def solve(strA, strB, MOD):
    A = 0 
    for x in strA:
        A = (A * 10 + int(x)) % MOD 
    
    res = 1 
    for x in strB:
        res = pow(res, 10, MOD) * pow(A, int(x), MOD) % MOD
    
    return res 

strA = input()
strB = input()
MOD = int(input())
print(solve(strA, strB, MOD))