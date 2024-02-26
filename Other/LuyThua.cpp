#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;


//? Tính a*b mod n
ll binaryMul(ll a, ll b, ll n) {
    ll res = 0; a %= n;
    while (b > 0) {
        if (b & 1) res = (res+a) % n;
        a = (2*a) % n;
        b /= 2;
    }
    return res;
}

//? Tính a^b mod n
ll binaryPow(ll a, ll k, ll n) {
    long long res = 1; a %= n;
    while (k > 0) {
        if (k & 1) res = binaryMul(res, a, n);
        a = binaryMul(a, a, n) % n;
        k /= 2;
    }
    return res;
}
 
int main() {
    ll a, b, c; 
    cin >> a >> b >> c;
    cout << binaryPow(a, b, c);
    return 0;
}