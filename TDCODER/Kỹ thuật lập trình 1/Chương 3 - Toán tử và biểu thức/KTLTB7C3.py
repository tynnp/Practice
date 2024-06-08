n = int(input())

h = n // 3600
m = (n % 3600) // 60
s = n % 3600 % 60

print("{:02}:{:02}:{:02}".format(h, m, s))
