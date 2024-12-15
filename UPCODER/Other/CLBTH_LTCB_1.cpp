#include <iostream>
using namespace std;

int main() {
    long long n, cnt = 0;
    cin >> n;
    
    while (n <= 1000000000) {
        cnt++;
        n <<= 1;
    }
    
    cout << cnt;
    return 0;
}