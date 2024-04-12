#include <iostream>
#define ll long long
using namespace std;

bool prime(ll n) {
    for (ll i = 2; i*i <= n; i++) 
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ll n, cnt(0);
    cin >> n;
    
    for (ll i = 2; i*i <= n; i++) {
        if (prime(i) && i*i*i*i < n) cnt++;
        if (i*i*i*i >= n) break;
    }
    
    cout << cnt;
    return 0;
}