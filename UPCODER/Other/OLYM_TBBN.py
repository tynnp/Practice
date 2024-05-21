n = int(input())

if n == 1 or n == 2:
    print(0)
elif n == 3:
    print(1)
else:
    f1, f2, f3 = 0, 0, 1
    for i in range(4, n + 1):
        fn = f1 + f2 + f3
        f1, f2, f3 = f2, f3, fn
    print(fn)
