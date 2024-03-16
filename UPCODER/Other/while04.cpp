#include <iostream>
using namespace std;
 
int main() {
    int n, k = 2, cnt = 0;
    cin >> n;

    while (n > 1) {
        if (n % k == 0) {
            if (cnt++) cout << "*";
            n /= k, cout << k;
        }

        else if (k == 2) k++;
        else k += 2;
    }
    
    return 0;
}