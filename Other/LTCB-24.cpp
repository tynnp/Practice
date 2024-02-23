#include <iostream>
using namespace std;

int main() {
    long long n; 
    cin >> n;

    for (long long i = 1; i <= n/2; i++) 
        if (n % i == 0 && i % 2 != 0) 
            cout << i << endl;
    
    if (n % 2 != 0) cout << n;
    return 0;
}