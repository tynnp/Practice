def run(n):
    return sum(int(x) for x in n)

try:
    while True:
        n = input()
        if n == '':
            break
        print(run(n))
        
except EOFError:
    pass