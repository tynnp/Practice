#include <bits/stdc++.h>
using namespace std;

bool check(int n) { return (int)sqrt(n) == sqrt(n); }

int main() {
    int n, cur(0), ans(0);
    cin >> n;

    vector<int> v(n + 1), s(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) {
        if (check(v[i]))
            cur++;
        else
            cur = 0;
        ans = max(cur, ans);
    }

    cout << ans;
    return 0;
}