#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, a, b, c;
    cin >> T;
    
    while (T--) {
        cin >> a >> b >> c;
        if (c > 0) cout << "CURVE UP\n";
        else if (c < 0) cout << "CURVE DOWN\n";
        else cout << "NO CURVE\n";
    }

    return 0;
}