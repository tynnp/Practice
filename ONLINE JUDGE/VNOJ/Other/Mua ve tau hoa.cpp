#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000000

const int MAXN = 1000005;
ll n, a, b, L[4], C[4];
ll arr[MAXN], dp[MAXN];

int main() {
    cin >> L[1] >> L[2] >> L[3] >> C[1] >> C[2] >> C[3];
    cin >> n >> a >> b;
    if (a > b) swap(a, b);

    for (int i = 2; i <= n; i++) 
        cin >> arr[i];

    fill(dp + a + 1, dp + n + 1, LLONG_MAX-2*INF);
    
    for (int i = a + 1; i <= b; i++) {
        for (int j = 1; j <= 3; j++) {
            int k = lower_bound(arr + 1, arr + n + 1, arr[i] - L[j]) - arr;
            dp[i] = min(dp[i], dp[k] + C[j]);
            //cout << k << " " << dp[k] << " " << dp[i] << endl;
        }
    }

    cout << dp[b];
    return 0;
}
