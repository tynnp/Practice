#include <iostream>
using namespace std;

bool nguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    bool check = true;

    for (int i = 2; i <= n; i++) {
        if (nguyenTo(i)) {
            cout << i << " ";
            check = false;
        }
    }

    if (check) cout << -1;
    return 0;
}