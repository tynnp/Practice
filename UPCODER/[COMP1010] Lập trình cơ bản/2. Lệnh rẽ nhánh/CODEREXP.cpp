#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int coBan, trungBinh, nangCao, kho;
    cin >> coBan >> trungBinh >> nangCao >> kho;
    int exp = coBan*10 + trungBinh*20 + nangCao*30 + kho*40;
    cout << exp << '\n';
    
    if (exp == 0) cout << "Coder So Sinh";
    else if (exp < 50) cout << "Coder Lop Mam";
    else if (exp < 100) cout << "Coder Lop Choi";
    else if (exp < 500) cout << "Coder Lop La";
    else if (exp < 1000) cout << "Coder Tieu Hoc";
    else if (exp < 1500) cout << "Coder THCS";
    else if (exp < 2000) cout << "Coder THPT";
    else if (exp < 2500) cout << "Coder Trung Cap";
    else if (exp < 3500) cout << "Coder Cao Dang";
    else if (exp < 4200) cout << "Coder Dai Hoc";
    else if (exp < 5500) cout << "Coder Thac Si";
    else if (exp < 7000) cout << "Coder Tien Si";
    else cout << "Coder Giao Su";
    return 0;
}