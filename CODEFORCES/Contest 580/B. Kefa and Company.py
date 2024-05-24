def heSoMax(n, d, banBe):
    banBe.sort(key=lambda x: x[0])
    
    heSoMax = 0
    cur = 0
    start = 0
    
    for end in range(n):
        cur += banBe[end][1]
        
        while banBe[end][0] - banBe[start][0] >= d:
            cur -= banBe[start][1]
            start += 1
 
        heSoMax = max(heSoMax, cur)
    
    return heSoMax
 
n, d = map(int, input().strip().split())
banBe = [tuple(map(int, input().strip().split())) for _ in range(n)]
 
ketQua = heSoMax(n, d, banBe)
print(ketQua)
