#include <iostream>
#include <algorithm>
using namespace std;

bool checkHT(int n) {
    int res = 0;
    int tmp = n;

    while (tmp > 0) {
        res = res*10 + tmp%10;
        tmp /= 10;
    }

    return __gcd(res, n) == 1;
}

int main() {
    int n;
    cin >> n;
    cout << (checkHT(n) ? "YES" : "NO");
}