#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x, n; 
    cin >> x >> n;
    float y = x, res = x;
    for (int i = 3; i <= 2*n + 1; i += 2) y *= x*x, res += y;
    cout << fixed << setprecision(2) << res;
    return 0;
}