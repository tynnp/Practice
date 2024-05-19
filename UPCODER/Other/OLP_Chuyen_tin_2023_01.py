def nhanMaTran(A, B, M):
    return [
        [(A[0][0] * B[0][0] + A[0][1] * B[1][0]) % M, (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % M],
        [(A[1][0] * B[0][0] + A[1][1] * B[1][0]) % M, (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % M]
    ]

def luyThuaMaTran(mat, exp, M):
    ketQua = [[1, 0], [0, 1]]
    coSo = mat
    
    while exp > 0:
        if exp % 2 == 1:
            ketQua = nhanMaTran(ketQua, coSo, M)
        coSo = nhanMaTran(coSo, coSo, M)
        exp //= 2
    
    return ketQua

def fibonacci(n, M):
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    F = [[1, 1], [1, 0]]
    ketQua = luyThuaMaTran(F, n-1, M)
    
    return ketQua[0][0]

def ucln(x, y):
    while y:
        x, y = y, x % y
    return x

def timUclnFibonacci(a, b, M):
    g = ucln(a, b)
    return fibonacci(g, M)

a, b, M = map(int, input().split())
print(timUclnFibonacci(a, b, M))
