#include <iostream>
using namespace std;

int main() {
    string res = "";
    long long n;
    cin >> n;

    while (n > 0) {
        if (n & 1) res = '4' + res;
        else n -= 2, res = '7' + res;
        n /= 2;
    }

    cout << res;
    return 0;
}