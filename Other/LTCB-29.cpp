#include <iostream>
using namespace std;

int main() {
    int n, result = 0; 
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (n%i == 0 && (n/i)%2 != 0) {
            result = n/i; 
            break;
        }
    }
    
    cout << result;
    return 0;
}