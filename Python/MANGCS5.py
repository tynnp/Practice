from math import sqrt

lst = map(int, input().split())

def cp(n):
    return int(sqrt(n)) == sqrt(n)

res = 0
for i in lst:
    if cp(i): res += i

print(res)