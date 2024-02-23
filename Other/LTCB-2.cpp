#include <iostream>
using namespace std;

int main() {
    long long n, S = 0; 
    cin >> n;

    if (n < 1) {
        cout << -1; 

    } else {
        while (n > 0) 
            S += n*n, n--;
        cout << S;
    }
    
    return 0;
}