#include <iostream>
#define endl '\n'
using namespace std;

void check(int n, int num, char x, char y, char z) {
    if (n == 1) cout << num << " " << x << " " << y << endl;
    else {
        check(n-1, n-1, x, z, y);
        check(1, num, x, y, z);
        check(n-1, n-1, z, y, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    check(n, n, 'A', 'C', 'B');
    return 0;
}