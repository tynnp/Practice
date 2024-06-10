def run(n, x, ga):
    def soTrungThuDuoc(thoiGian):
        tongSoTrung = 0
        for p, t in ga:
            if thoiGian >= p:
                tongSoTrung += 1 + (thoiGian - p) // t
        return tongSoTrung

    left, right = 0, 10**18
    while left < right:
        mid = (left + right) // 2
        if soTrungThuDuoc(mid) >= x:
            right = mid
        else:
            left = mid + 1

    return left

n, x = map(int, input().strip().split())
ga = [tuple(map(int, input().strip().split())) for _ in range(n)]
print(run(n, x, ga))