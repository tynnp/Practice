#include <iostream>
using namespace std;

int main() {
    long long n, dem = 0; 
    cin >> n;

    for (long long i = 1; i <= n/2; i++) 
        if (n % i == 0) dem++;
    
    cout << dem + 1;
    return 0;
}