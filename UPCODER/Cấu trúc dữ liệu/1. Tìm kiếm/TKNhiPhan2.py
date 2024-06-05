def binarySearch(arr, n, x):
    left = 0
    right = n - 1
    mid = (left + right)//2
    
    while left <= right:
        if arr[mid] < x: left = mid + 1
        elif arr[mid] > x: right = mid - 1
        else: return mid
        mid = (left + right)//2
    return -1
    
n, x = map(int, input().split())
arr = list(map(int, input().split()))
ans = binarySearch(arr, n, x)

if ans == -1:
    print(-1)
else:
    for i in range(0, n):
        if arr[i] == x:
            print(i, end = ' ')