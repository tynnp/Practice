#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, x; 
    cin >> a >> x;
    cout << (a + sin(x)) / sqrt(a*a + x*x + 1);

    return 0;
}