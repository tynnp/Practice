def sequentialSearch(arr, n, x):
    tmp = -9999999999
    res = -1
    for i in range(0, n):
        if arr[i] > tmp and arr[i] <= x:
            tmp = arr[i]
            res = i
    return res
    
x = int(input())
arr = list(map(int, input().split()))
ans = sequentialSearch(arr, len(arr), x)

print(ans)