def powerMod(x, n, mod):
    if n == 0:
        return 1
    elif n % 2 == 0:
        temp = powerMod(x, n // 2, mod)
        return (temp * temp) % mod
    else:
        temp = powerMod(x, n - 1, mod)
        return (x * temp) % mod

x, n = map(int, input().split())
result = powerMod(x, n, 10000)
print(result)