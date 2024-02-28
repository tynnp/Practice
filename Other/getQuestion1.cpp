#include <iostream>
using namespace std;

int tongChuSo(long long n) {

    if (n < 10) return n;

    int res = 0;
     while (n > 0) {
        res += n%10;
        n /= 10;
    }

    return tongChuSo(res);
}

int main() {
    long long n;
    cin >> n;
    cout << tongChuSo(n);
    return 0;
}