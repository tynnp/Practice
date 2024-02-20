#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double x; cin >> x;
    if (x < 2.5) cout << "NHAP SAI";
    else cout << sqrt(2*x - 5);
    return 0;
}