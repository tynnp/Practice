import sys
import math
input = sys.stdin.read
data = input().split()

k = int(data[0])
n, c = map(int, data[1:3])
MOD = 998244353

print(c * pow(c - 1, n - 1, MOD) % MOD, end="")
