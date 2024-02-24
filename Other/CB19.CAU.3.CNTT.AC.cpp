#include <iostream>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b;

    if (a < 10) x = 0 + a%10;
    else x = a%10 + a/10%10;

    if (b < 10) y = 0 + b%10;
    else y = b%10 + b/10%10;

    if (x > y) cout << x - y;
    else if (x < y) cout << x + y;
    else cout << x * y;

    return 0;
}