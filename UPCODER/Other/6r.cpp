#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        if (1 <= gcd(x, y) && gcd(x, y) <= 2) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}
