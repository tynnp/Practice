#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    bool check = true; 
    cin >> n;

    if (n < 2) cout << 0; 
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << 0; 
                check = false;
                break;
            }
        }
        if (check) cout << 1;
    }

    return 0;
}