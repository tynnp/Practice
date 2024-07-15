n = int(input())

while n:
    print(n,end=' ')
    if n == 1: break
    n = 3*n + 1 if n & 1 else n//2

