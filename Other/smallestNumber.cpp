#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    long long n; 

    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            long long k = sqrt(n*i);
            if (k*k == n*i) {
                cout << i << endl; 
                break;
            }
        }
    }

    return 0;
}