#include <iostream>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;

bool check(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) return false;
    return true;
} 

int main() {
    ll n, res = -10e6; 
    vector<ll> vt;
    while (cin >> n) vt.push_back(n);

    for (ll x : vt) 
        if (check(x) && x > res) res = x;

    cout << (res == -10e6 ? 0 : res);
    return 0;
}