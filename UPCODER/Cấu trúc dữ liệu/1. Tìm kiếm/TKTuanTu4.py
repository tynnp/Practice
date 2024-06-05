def sequential(arr, n, x):
    tmp = -9999999999
    res = -1
    for i in range(0, n):
        if arr[i] > tmp and arr[i] <= x:
            tmp = arr[i]
            res = i
    return res
    
x = int(input())
arr = list(map(int, input().split()))
ans = sequential(arr, len(arr), x)

if ans == -1:
    print(-1)
else:
    for i in range(0, len(arr)):
        if arr[i] == arr[ans]:
            print(i, end = " ")