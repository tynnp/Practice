#include <iostream>
using namespace std;

bool gcd(int a, int b) {
    if (b == 0) return a == 1;
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b; 
    cin >> a >> b;
    cout << (gcd(a, b) ? "yes" : "no");
    return 0;
}