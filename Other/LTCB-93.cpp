#include <iostream>
#include <cmath>
using namespace std;

bool check(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    long long n; cin >> n;
    cout << (check(n) ? "Yes" : "No");
    return 0;
}