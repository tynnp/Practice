#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, r; cin >> a;
    r = a/2;

    cout << a*a - (M_PI*r*r);
    return 0;
}