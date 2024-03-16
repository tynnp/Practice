#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
    int n, res = 0, m = 0; 
    cin >> n;

    if (n < 2) {
        cout << "NO"; 
    } else {
        cout << "Tong cac so nguyen to <= " << n << " la:\n";

        for (int i = 2; i <= n; i++) {
            int k = 0;
            for (int j = 2; j <= sqrt(i); j++) 
                if (i % j == 0) k++;

            if (k == 0) {
                if (m > 0) cout << " + ";
                cout << i; 
                res += i; 
                m++;
            } 
        }

        cout << " = " << res;
    }

    return 0;
}