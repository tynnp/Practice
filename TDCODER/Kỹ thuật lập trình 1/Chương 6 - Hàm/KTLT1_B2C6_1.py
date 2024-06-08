def sum(n):
    ans = 0
    for i in range(1, n+1):
        if i % 2 != 0:
            ans += i
    return ans 

n = int(input())
print(sum(n))