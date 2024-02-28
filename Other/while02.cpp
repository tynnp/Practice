#include <iostream>
using namespace std;
 
int main() {
    long long n, k = 0; 
    cin >> n;

    while (n) {
        if (n % 10 == 0 && k) cout << 0;
        else if (n % 10 != 0) k++, cout << n % 10;
        n /= 10;
    }

    return 0;
}