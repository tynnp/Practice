def gcd(a, b):
    if b == 0: 
        return a
    else:
        return gcd(b, a % b)

class PhanSo:
    def __init__(self, tu, mau):
        self.tu = tu
        self.mau = mau 

    # Quá tải cộng
    def __add__(self, other):
        # Kiểm tra xem other có phải lớp PhanSo không
        if isinstance(other, PhanSo): 
            resTu = self.tu*other.mau + self.mau*other.tu
            resMau = self.mau * other.mau
            return PhanSo(resTu, resMau)
        else:
            raise ValueError("Unsupported operand type")

    # Quá tải trừ   
    def __sub__(self, other):
        if isinstance(other, PhanSo): 
            resTu = self.tu*other.mau - self.mau*other.tu
            resMau = self.mau * other.mau
            return PhanSo(resTu, resMau)
        else:
            raise ValueError("Unsupported operand type")

    # Quá tải bằng 
    def __eq__(self, other):
        if isinstance(self, PhanSo):
            return (self.tu * other.mau) == (self.mau * other.tu)
        else: 
            return False

    # Quá tải khác
    def __ne__(self, other):
        if isinstance(self, PhanSo):
            return (self.tu * other.mau) != (self.mau * other.tu)
        else: 
            return False

    # Quá tải xuất
    def __str__(self):
        ucln = gcd(self.tu, self.mau)
        self.tu /= ucln
        self.mau /= ucln
        return f"{int(self.tu)}/{int(self.mau)}"

a, b = map(int, input().split())
n, m = map(int, input().split())
p1 = PhanSo(a, b)
p2 = PhanSo(n, m)
print(p1 + p2)
