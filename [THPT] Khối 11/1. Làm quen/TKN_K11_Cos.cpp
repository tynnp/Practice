#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double x, k;
    cin >> x;

    k = (abs(2*x + 3) / cos(x)) + sqrt(2 + cos(x));
    cout << k;
    return 0;
}