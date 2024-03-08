import re

def trungBinhSo(chuoi):
    so = re.findall(r'\d+', chuoi)
    tong = sum(int(num) for num in so)
    trungBinh = round(tong / len(so), 2)
    return trungBinh

chuoi = input()
kq = trungBinhSo(chuoi)
print(kq)
