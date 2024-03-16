#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long n; 
    float x, res = 1; 
    cin >> x >> n;
    for (int i = 1; i <= n; i++) res *= x;
    cout << fixed << setprecision(3) << res;
    return 0;
}