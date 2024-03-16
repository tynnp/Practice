#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    double tong = 0;

    for (int i = 1; i <= n; i++)
        tong += 1/pow(i, 3);
    
    cout << fixed << setprecision(3) << tong;
    return 0;
}