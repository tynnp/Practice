#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double a, b; 
    cin >> a >> b;

    cout << fixed << setprecision(1) << (a + b)/2;
    return 0;
}