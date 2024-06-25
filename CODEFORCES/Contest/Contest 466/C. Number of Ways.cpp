#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, cnt(0), ans(0);
    ll sum(0), div(0), prefixSum(0);
    cin >> n;

    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
        sum += x;
    }

    if (sum % 3 != 0) cout << 0;
    else {
        div = sum / 3;
        for (int i = 0; i < n - 1; i++) {
            prefixSum += v[i];

            if (prefixSum == 2 * div && i < n - 1)
                ans += cnt;

            if (prefixSum == div) cnt++;
        }

        cout << ans;
    }

    return 0;
}