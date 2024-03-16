def soKeo(tien, gia):
    keo = tien // gia
    voKeo = keo 

    while voKeo >= 2:
        doiuoc = voKeo // 2
        keo += doiuoc
        voKeo = doiuoc + (voKeo % 2)
    
    return keo

tien, gia = map(int, input().split())
print(soKeo(tien, gia))
