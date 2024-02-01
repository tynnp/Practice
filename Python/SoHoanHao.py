n = int(input())
res = 0

for i in range(2, n//2):
    res += n/i + i if n%i == 0 else 0

print("Yes" if res + 1 == n else "No")