#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}