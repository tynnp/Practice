a = [int(x) for x in input().split()]
if len(a) == 1:
    b = [int(x) for x in input().split()]
    a = a[0]
    b = b[0]
else:
    b = a[1]
    a = a[0]


for i in input().split():
    if i == '+':
        print(a, i, b, '=', a + b, sep = '')
    elif i == '-':
        print(a, i, b, '=', a - b, sep = '')
    elif i == '*':
        print(a, i, b, '=', a * b, sep = '')
    elif i == '/':
        print(a, i, b, '=', a // b, sep = '')
    elif i == '%':
        print(a, i, b, '=', a % b, sep = '')