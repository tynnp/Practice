#include <iostream>
using namespace std;

long long S(long long n) {
    if (n == 1) return 1;
    long long res = 0;
    for (long long i = 1; i <= n; i++)    
        res += i;
    return res + S(n-1);
}

long long P(long long n) {
    if (n == 1) return 1;
    long long res = 1;
    for (long long i = 1; i <= n; i++)
        res *= i;
    return res + P(n-1);
}

int main() {
    long long n; cin >> n;
    cout << "S(" << n << ") = " << S(n) << endl;
    cout << "P(" << n << ") = " << P(n) << endl;
    return 0;
}