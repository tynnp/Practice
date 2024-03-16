a, b = map(int, input().split())
arr = input().split()
for char in arr:
    if char == '+':
        print("{}{}{}={}".format(a, char, b, a+b))
    elif char == '-':
        print("{}{}{}={}".format(a, char, b, a-b))
    elif char == '*':
        print("{}{}{}={}".format(a, char, b, a*b))
    elif char == '/':
        print("{}{}{}={}".format(a, char, b, a//b))
    else:
        print("{}{}{}={}".format(a, char, b, a%b))