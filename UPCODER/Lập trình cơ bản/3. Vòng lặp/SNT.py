import math

def check(n):
    for i in range(2, int(math.sqrt(n) + 1)):
        if n % i == 0:
            return False
    return n > 1
    
n = int(input())
print("true" if check(n) else "false")