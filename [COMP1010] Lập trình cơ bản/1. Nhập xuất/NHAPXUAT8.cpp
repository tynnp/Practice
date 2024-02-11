#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << fixed << setprecision(1) << (a+b+c)/(d+e+f);
    return 0;
}