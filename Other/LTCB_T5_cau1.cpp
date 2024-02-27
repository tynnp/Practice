#include <iostream>
#include <cmath>
using namespace std;
 
bool SNT(int n) {
    for (int i = 2; i*i <= n; i++) 
    if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n, m, k = 0, x = 0; 
    cin >> n >> m;

    for (int i = n; i <= m; i++) {
        if (SNT(i)) {
            if (x) cout << " ";
            cout << i; 
            k++; x++;
        }
    }

    if (k == 0) cout << -1;
    return 0;
}