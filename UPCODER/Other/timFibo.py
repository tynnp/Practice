n = int(input())
a, b = 0, 1
for i in range(n):
    b, a = a + b, b
print(a)
