def binarySearch(arr, n, x):
    left = 0
    right = n-1
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
print(ans)