#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;

ull binaryMul(ull a, ull b, ull m) {
    a = a % m;
    ull res = 0;

    while (b > 0) {
        if (b & 1)
            res = (res + a) % m;
        a = (a << 1) % m;
        b /= 2;
    }

    return res;
}

ull binaryPow(ull a, ull b, ull m) {
    a = a % m;
    ull res = 1;

    while (b > 0) {
        if (b & 1)
            res = binaryMul(res, a, m);
        a = binaryMul(a, a, m) % m;
        b /= 2;
    }

    return res;
}

int main() {
    ull k, n;
    cin >> k >> n;
    
    ull value[5] = {0};
    for (int i = 1; i < 5; i++)
        value[i] = int((pow(k, i)-1) / (k - 1)) % 10;
    value[0] = value[4] % 10;
    
    cout << value[n % 4];
    return 0;
}