import math

def check(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return n > 1

n = int(input())
ans = 0

for i in range(2, n+1):
    if check(i):
        ans += 1
        print(i, end = ' ')

print(-1 if ans == 0 else '')