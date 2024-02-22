#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int giai_thua(double n) {
    if (n == 1) return 1;
    return n*giai_thua(n - 1);
}
 
int main() {
    double n, x; 
    cin >> x >> n;
    double res = 1 + x;

    while (n > 0) {
        res += pow(x, 2*n + 1)/giai_thua(2*n + 1);
        n--;
    }

    cout << setprecision(4) << res;
    return 0;
}