#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double toan, van, anh, mon1, mon2, mon3, kk, dtb12, ut;
    cin >> toan >> van >> anh >> mon1 >> mon2 >> mon3 >> kk >> dtb12 >> ut;
    double toHop = (mon1 + mon2 + mon3)/3;
    double dxtn = (((toan + van + anh + toHop + kk)/4)*7 + (dtb12*3))/10 + ut;

    if (toan < 1 || van < 1 || anh < 1 || mon1 < 1 || mon2 < 1 || mon3 < 1)
        cout << "Khong dau tot nghiep\n";

    else if (dxtn < 5) {
        cout << "Khong dau tot nghiep\n";
        cout << round(dxtn*100)/100;
        
    } else {
        cout << "Dau tot nghiep\n";
        cout << round(dxtn*100)/100;
    }

    return 0;
}