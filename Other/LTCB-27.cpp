#include <iostream>
using namespace std;

int main() {
    long long n, dem = 0; 
    cin >> n;
    for (long long i = 1; i <= n/2; i++) 
        if (n % i == 0 && i % 2 == 0) dem++;
    
    cout << (n % 2 == 0 ? dem + 1 : dem);
    return 0;
}