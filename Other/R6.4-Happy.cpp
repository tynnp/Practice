#include <iostream>
using namespace std;

long long C(long long n, long long k) {
    if (k == n) return 1;
    if (k == 1) return n;
    return C(n-1, k) + C(n-1, k-1);
}

int main() {
    long long n;
    cin >> n;
    cout << n*(n-1)*(n-2)*(n-3)*(n-4)*C(n, 5);
    return 0;
}