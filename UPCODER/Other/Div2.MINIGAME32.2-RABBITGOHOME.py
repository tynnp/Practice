a, b = map(int, input().split())
ans = [[0] * 20 for _ in range(20)]

def dp(x, y, ans):
    if x < 0 or y < 0 or x < y: return 0
    if x == 0 and y == 0: return 1
    if ans[x][y] != 0: return ans[x][y]
    ans[x][y] = dp(x-1, y, ans) + dp(x, y-1, ans)
    return ans[x][y]

print(dp(a, b, ans))

