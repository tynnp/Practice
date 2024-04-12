#include <iostream>
using namespace std;

int gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    long long a, b, c;
    cin >> a >> b;
    c = gcd(a, b);
    cout << c << endl;
    cout << a/c << " " << b/c;
    return 0;
}