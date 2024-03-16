#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test; cin >> test;

    while (test--) {
        int n, k, res = -10e5;
        int checkEven = 0;
        cin >> n >> k;

        while (n--) {
            int tmp; cin >> tmp;
            res = max(res, tmp % k);
            if (tmp % 2 == 0) checkEven++;
            if (tmp % k == 0) res = k;
        }

        if (k == 4) {
            if (checkEven >= 2 || res == k) cout << 0 << endl;
            else if (checkEven == 1) cout << 1 << endl;
            else cout << min(k - res, 2) << endl;
        } else cout << k - res << endl;
    }

    return 0;
}