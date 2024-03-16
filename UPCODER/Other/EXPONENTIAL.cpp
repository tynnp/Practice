#include <iostream>
#define ll long long 
using namespace std;

const int n = 100;

ll binaryMul(ll a, ll b, ll n) {
    a = a % n;
    ll res = 0;

    while (b > 0) {
        if (b & 1) res = (res+a) % n;
        a = (2*a) % n;
        b /= 2;
    }

    return res;
}

ll binaryPow(ll a, ll b, ll n) {
    a = a % n;
    ll res = 1;

    while (b > 0) {
        if (b & 1) res = binaryMul(res, a, n);
        a = binaryMul(a, a, n) % n;
        b /= 2;
    }

    return res;
}

int main() {
    ll a, b, res;
    cin >> a >> b;

    res = binaryPow(a, b, n);
    if (res < 10) cout << 0;
    cout << res;

    return 0;
}