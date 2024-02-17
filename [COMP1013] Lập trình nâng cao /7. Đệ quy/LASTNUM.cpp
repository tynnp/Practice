#include <iostream>
using namespace std;

int lastNum(int n) {
    if (n < 10) return n;
    int res = n%10 + n/10;
    return lastNum(res);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    cout << lastNum(n);
    return 0;
}