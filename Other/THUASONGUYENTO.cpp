#include <iostream>
using namespace std;

int main() {
    int n, i = 2, k = 0; 
    cin >> n;

    while (n > 1) {
        while (n % i == 0) {
            n /= i; 
            if (k++) cout << "x";
            cout << i;
        } 
        
        if (i == 2) i++;
        else i += 2;
    }

    return 0;
}