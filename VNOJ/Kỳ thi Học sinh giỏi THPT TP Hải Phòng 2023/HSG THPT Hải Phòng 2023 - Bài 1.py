import math

n = int(input())
k = int(math.sqrt(n))
ans = 1 if k == math.sqrt(n) else 0

for i in range(1, k+1):
    if i != k and n % i == 0:
        ans += 2

print(ans)