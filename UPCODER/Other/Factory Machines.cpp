#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m;
int a[MAXN];

int check(int mid) {
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += mid / a[i];
        if (sum >= m)
            break;
    }
    
    return sum;
}

void solve() {
    int left = 0, right = LLONG_MAX;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (check(mid) >= m)
            right = mid - 1;
        else 
            left = mid + 1;
    }
    
    cout << left;
}

signed main() {
    fastIO;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve();
    return 0;
}