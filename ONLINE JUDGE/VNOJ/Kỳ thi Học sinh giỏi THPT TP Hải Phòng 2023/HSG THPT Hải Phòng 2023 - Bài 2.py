s = input()

ans = 0
for i in range(len(s)):
    if s[i].isdigit():
        ans += 1
print(ans)