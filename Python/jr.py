n = int(input())

res = n*n*(n-1)*(n+1)//12

print(res % (1000000007))