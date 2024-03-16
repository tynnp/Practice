#include <iostream>
#include <vector>
#define ll long long
using namespace std;

void sieve(int L, int R) {
    vector<bool> isPrime(R - L + 1, true);

    for (ll i = 2; i*i <= R; i++) 
        for (ll j = max(i*i, (L+i-1)/i*i); j <= R; j += i) 
            isPrime[j - L] = false;
    if (1 >= L) isPrime[1 - L] = false;

    for (ll x = max(L, 2); x <= R; x++)
        if (isPrime[x - L]) {
            cout << x << endl;
        }
}
 
int main() {
    ll a, b; 
    cin >> a >> b;
    sieve(a, b);
    return 0;
}