a = int(input())

if a < 3:
    print(-1)
elif a % 2 != 0:
    b = a*a // 2
    c = b + 1
    print(b, c)
else:
    b = a*a // 4 - 1
    c = b + 2
    print(b, c)