def binaryMul(a, b, m):
    res = 0
    a = a % m
    while b > 0:
        if b % 2 != 0:
            res = (res + a) % m
        a = (a << 1) % m
        b //= 2
    return res

def binaryPow(a, b, m):
    res = 1
    a = a % m
    while b > 0:
        if b % 2 != 0:
            res = binaryMul(res, a, m)
        a = binaryMul(a, a, m)
        b //= 2
    return res
    
a, b = map(int, input().split())
print(binaryPow(a, b, 1000000007))