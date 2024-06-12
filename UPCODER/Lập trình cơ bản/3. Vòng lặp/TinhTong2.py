import math

def check(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return n > 1

def run(n):
    return sum(int(x) for x in n if check(int(x)))

try:
    while True:
        n = input()
        if n == '':
            break
        print(run(n))
        
except EOFError:
    pass