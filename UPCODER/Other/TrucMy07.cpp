#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
 
bool check(ll n) {
    ll x = static_cast<ll>(round(pow(n, 1.0/3.0)));
    return x*x*x == n;
}

int main() {
    int test; 
    cin >> test;

    while (test--) {
        ll n; 
        cin >> n;
        cout << (check(n) ? "YES\n" : "NO\n");
    }
    
    return 0;
}