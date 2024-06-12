def check(n):
    res = 0
    for i in range(1, n):
        res += i if n % i == 0 else 0
    return res == n

n = int(input())
print("Yes" if check(n) else "No")