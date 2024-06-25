#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, ans(0);
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    for (int i = 0; i < n; i++)
        c[i] = a[i] - b[i];

    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        if (c[i] <= 0) continue;
        int j = lower_bound(c.begin(), c.end(), -c[i]+1) - c.begin();
        ans += i - j;
    }

    cout << ans;
    return 0;
}