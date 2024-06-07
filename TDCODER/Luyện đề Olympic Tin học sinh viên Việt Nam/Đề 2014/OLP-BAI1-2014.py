import math

a, b = map(float, input().split())
ans = 0

for i in range(math.ceil(a), math.floor(b)+1):
    ans += i

print(ans)