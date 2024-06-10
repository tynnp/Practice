#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll sum[100005] = {0};

bool check(ll n) {
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    ll n, m, a, b, tmp;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        sum[i] = sum[i-1] + tmp;
    }

    while (m--) {
        cin >> a >> b;
        cout << check(sum[b] - sum[a-1]) << '\n';
    }

    return 0;
}