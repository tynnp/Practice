s = input()
x = ''.join(c if c.isdigit() else ' ' for c in s)
num = map(int, x.split())
ans = sum(num)
print(ans)