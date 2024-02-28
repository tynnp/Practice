#include <iostream>
using namespace std;
 
int main() {
    int n, i = 1; 
    cin >> n;

    while (i <= n) {
        if (n % i == 0 && (n / i) % 2 != 0) {
            cout << n / i;
            break;
        } 
        i++;
    }
    
    return 0;
}