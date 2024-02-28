#include <iostream>
using namespace std;
 
int main() {
    long long n; 
    cin >> n;
    long long tmp = n, res = 0;
    while (tmp) res = res*10 + tmp % 10, tmp /= 10;
    cout << n + res;
    return 0;
}