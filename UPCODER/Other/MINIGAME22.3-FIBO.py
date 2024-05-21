MOD = 10**9 + 7

def maTran(A, B):
    res = [[0, 0], [0, 0]]
    
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][j] += A[i][k] * B[k][j]
                res[i][j] %= MOD
    
    return res

def power(matrix, n):
    res = [[1, 0], [0, 1]]
    base = matrix
    
    while n > 0:
        if n % 2 == 1:
            res = maTran(res, base)
        base = maTran(base, base)
        n //= 2
    
    return res

def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    
    T = [[1, 1], [1, 0]]
    Tn = power(T, n - 1)
    return Tn[0][0]

n = int(input())
print(fibonacci(n))
