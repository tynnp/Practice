a = int(input())
b = int(input())
c = input()

ans = 0
if c == "/" and b == 0:
    print("Khong chia duoc")
elif c == "+":
    ans = a + b
    print(ans)
elif c == "-":
    ans = a - b
    print(ans)
elif c == "*":
    ans = a * b
    print(ans)
elif c == "/":
    ans = a / b
    print("%.1f" %ans)
else:
    print("Phep toan khong hop le")