a = float(input())
b = float(input())
c = a + b
ans = "%.6f" % c
print(ans.rstrip('0').rstrip('.'))
