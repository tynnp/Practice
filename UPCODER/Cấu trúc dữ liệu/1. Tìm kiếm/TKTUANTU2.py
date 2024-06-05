def sequentialSearch(arr, n, x):
    for i in range(0, n):
        if arr[i] == x:
            return i
    return -1
    
n, x = map(int, input().split())
arr = list(map(int, input().split()))
ans = sequentialSearch(arr, n, x)

if ans == -1:
    print(-1)
else:
    for i in range(0, n):
        if arr[i] == x:
            print(i, end = " ")