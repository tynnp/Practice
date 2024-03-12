#include <iostream>
#include <cmath>
using namespace std;

const int md = trunc(1e6) + 7;
const int mm = trunc(1e7);
int f[10000001];

int main() {
    int test, n, k;
    f[1] = 1;
    
    for (int i = 2; i <= mm; i++)
        f[i] = (1LL * f[i - 1] * 10 + 1) % md;
        
    for (int i = 2; i <= mm; i++)
        f[i] = (f[i] + f[i - 1]) % md;
        
    cin >> test;
    while (test--) {
        cin >> n >> k;
        cout << (1LL * k * f[n]) % md << endl;
    }
    
    return 0;
}