#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, x(0), y(0), z(0);
    cin >> t;

    while (t--) {
        cin >> a >> b >> c;
        x += a;
        y += b;
        z += c;
    }

    if (x == 0 && y == 0 && z == 0) cout << "YES";
    else cout << "NO";
    
    return 0;
}