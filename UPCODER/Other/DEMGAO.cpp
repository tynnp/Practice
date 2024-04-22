#include <iostream>
using namespace std;
#define ll long long

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    cout << b/k - (a-1)/k;
    return 0;
}