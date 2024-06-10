from math import *

n = int(input())
a = list(map(int, input().split()))

dp = [1] * (n + 1)
ans = 0

for i in range(1, n):
    for j in range(0, i):
        if a[j] < a[i]:
            dp[i] = max(dp[i], dp[j] + 1)
    ans = max(ans, dp[i])
    
print(ans)