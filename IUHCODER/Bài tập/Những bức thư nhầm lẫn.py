MOD = 10**9 + 7
MAXN = 10**6 + 1

n = int(input())

dp = [0] * MAXN
dp[0] = 1
dp[1] = 0

for i in range(2, n+1):
    dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % MOD
    
print(dp[n])