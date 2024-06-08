a = int(input())
b = int(input())

if a == 0:
    if b == 0:
        print("VSN")
    else:
        print("VN")
else:
    print("%.2f" %(-b/a))