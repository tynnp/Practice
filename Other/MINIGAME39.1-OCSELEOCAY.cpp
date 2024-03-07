#include <iostream>
using namespace std;

int main() {
    long long a, b, c, k;
    cin >> a >> b >> c;

    k = c - a;
    if (k % (a - b) == 0) cout << 1 + k/(a-b);
    else cout << 2 + k/(a-b);
    
    return 0;
}