#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double n, tong = 1, tich = 1;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        tich = 1;
        for (int j = 0; j <= i; j++)
            tich *= (double) 2*(j+1) / (2*j+3);
        tong += tich;
    }
    
    cout << fixed << setprecision(2) << tong;
    return 0;
}