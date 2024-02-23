#include <iostream>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;

    if (a*b > 0) cout << "YES";
    else if (a*b < 0) cout << "NO";
    else cout << 0;

    return 0;
}