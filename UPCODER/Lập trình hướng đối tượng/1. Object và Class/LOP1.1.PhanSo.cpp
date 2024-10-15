#include <iostream>
using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;

public:
    void nhap();    // thao tác nhập
    void xuat();    // thao tác xuất
};

int main() {
    PhanSo p;
    p.nhap();
    p.xuat();
}

void PhanSo::nhap() {
    cin >> tuSo >> mauSo;
}

void PhanSo::xuat() {
    cout << tuSo << '/' << mauSo;
}