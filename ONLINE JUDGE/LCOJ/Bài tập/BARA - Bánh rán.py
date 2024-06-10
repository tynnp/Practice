n, k = map(int, input().split())

ans = 2*n//k * 5
ans += 0 if 2*n % k == 0 else 5
print(max(ans, 10))