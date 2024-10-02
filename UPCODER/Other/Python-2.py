def pow(a, n):
    res = 1
    for _ in range(n):
        res *= a
    return res

x = int(input())
res = pow(x, 10) + pow(x, 5) + 1
print("f(x)= {}".format(res))
