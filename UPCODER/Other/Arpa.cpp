#include <iostream>
using namespace std;

int main() {
    int k, n = 8, res = 1;
    cin >> k;
    
    while (k > 0) {
        if (k & 1) res = (res*n) % 10;
        n = (n*n) % 10;
        k /= 2;
    }
    
    cout << res;
    return 0;
}