def sequentialSearch(arr, n, x):
    for i in range(0, n):
        if arr[i] == x: 
            return i
    return -1

n, x = map(int, input().split())
arr = list(map(int, input().split()))

ans = sequentialSearch(arr, n, x)
print(ans)
