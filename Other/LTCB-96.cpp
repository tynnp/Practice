#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x; cin >> x;
    if (x < 5) cout << fixed << setprecision(2) << -2*pow(x,2) + 4*x - 9;
    else cout << fixed << setprecision(2) << 2*pow(x, 2) + 5*x + 9;
    return 0;
}