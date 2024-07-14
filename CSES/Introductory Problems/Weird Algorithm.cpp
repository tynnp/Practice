#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n;
    cin >> n;
    
    do {
        cout << n << " ";
        if (n == 1 || n == 0) break;
        if (n & 1) n = n*3 + 1;
        else n = n / 2;
    } while (n);

    return 0;
}