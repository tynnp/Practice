#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b; 
    cin >> a >> b;
    if (a+b > -1) cout << a+b << " ";
    if (a-b > -1) cout << a-b << " ";
    if (a*b > -1) cout << a*b << " ";
    if (a+b < 0 && a-b < 0 && a*b < 0) cout << "impossible";
    return 0;
}