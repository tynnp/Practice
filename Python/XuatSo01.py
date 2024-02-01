n, m = map(int, input().split())

a = max(n, m)
b = min(n, m)

if n == m:
    print("Gia tri cua n va m bang nhau", end="")
else:
    for i in range(a, b-1, -1):
        print(i, end="")
        if i != b: print(end=" ")
    