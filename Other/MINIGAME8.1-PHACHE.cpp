#include <iostream>
using namespace std;

int main() {
    int a, b, c, MIN;
    cin >> a >> b >> c;

    MIN = min(a/1, min(b/2, c/4));
    if (MIN == 0) cout << 0;
    else cout << MIN*7;

    return 0;
}