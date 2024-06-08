h = int(input())
m = int(input())
s = int(input())
a = int(input())

s += a
if s >= 60: 
    s %= 60
    m += 1

if m >= 60:
    m %= 60
    h += 1

print("{:02}:{:02}:{:02}".format(h, m, s))
    