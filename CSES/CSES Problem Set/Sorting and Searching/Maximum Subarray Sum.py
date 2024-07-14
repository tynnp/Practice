n = int(input())
a = list(map(int, input().split()))

ans = sum = a[0]
for i in range(1, n):
    sum = max(a[i], sum + a[i])
    if sum > ans:
        ans = sum
print(ans)