n = int(input())
arr = list(map(int, input().split()))
dp = [1] * n

for i in range(1, n):
    if arr[i-1] == arr[i]:
        dp[i] = dp[i-1] + 1
        
mx = 0
for i in range(0, n):
    if dp[i] > mx:
        mx = dp[i]
        
print(n - mx)