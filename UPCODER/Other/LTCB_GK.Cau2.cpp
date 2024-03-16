#include <iostream>
using namespace std;
  
int main() {
    double gio_bat_dau, gio_ket_thuc; 
    cin >> gio_bat_dau >> gio_ket_thuc;
    double k = gio_ket_thuc - gio_bat_dau;
    cout << (k <= 3 ? k*30000 : (k - 3)* 21000 + 3*30000);   
    return 0;
}