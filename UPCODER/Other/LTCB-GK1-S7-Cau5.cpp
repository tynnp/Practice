#include <iostream>
using namespace std;
 
int main() {
    int gio_bat_dau, gio_ket_thuc; 
    cin >> gio_bat_dau >> gio_ket_thuc;

    if (gio_bat_dau < 8 || gio_bat_dau > 24 || gio_ket_thuc < 8 || gio_ket_thuc > 24 || gio_bat_dau > gio_ket_thuc) {
        cout << "NO"; 
    } else {
        int k = gio_ket_thuc - gio_bat_dau;
        if (k < 4) cout << k*30000;
        else if (k > 3) cout << (k - 3)*21000 + 90000;
    }
    
    return 0;
}