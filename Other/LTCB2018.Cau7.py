def check(soKyDieu):
    chuSo = [int(chu) for chu in str(soKyDieu)]
    chuSoTangDan = sorted(chuSo)
    chuSoGiamDan = sorted(chuSo, reverse=True)
    soNhoNhat = int("".join(map(str, chuSoTangDan)))
    soLonNhat = int("".join(map(str, chuSoGiamDan)))
    hieu = soLonNhat - soNhoNhat
    
    if hieu == soKyDieu:
        return "YES", soLonNhat, soNhoNhat
    else:
        return "NO", soLonNhat, soNhoNhat

soKyDieu = int(input())
ketQua, soLon, soNho = check(soKyDieu)
print(ketQua)
print(soLon, soNho)