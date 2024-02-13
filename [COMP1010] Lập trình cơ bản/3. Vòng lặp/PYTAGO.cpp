#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    if (n >= 5) {
        for (int i = 3; i <= n; i++) 
            for (int j = i+1; j <= n; j++) {
                int c = sqrt(i*i + j*j);
                if (c == sqrt(i*i + j*j) && c <= n && j < c)   
                    cout << i << " " << j << " " << c << '\n';
            }
    } else cout << -1;
    return 0;
}