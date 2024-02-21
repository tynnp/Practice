#include <iostream>
#define ll long long
using namespace std;

ll uocChung(ll a, ll b) {
    if (b == 0) return a;
    return uocChung(b, a % b);
}

int main() {
    ll a, b; 
    cin >> a >> b;
    cout << uocChung(a, b);
    return 0;
}