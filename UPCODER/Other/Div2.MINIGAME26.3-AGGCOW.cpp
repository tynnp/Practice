#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, c;
vector<int> v;

bool check(int mid) {
    int k = c;
    k--;
    
    int x = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[x] + mid) {
            x = i;
            k--;
        }
    }
    
    return k <= 0;
}

int search(int l, int r) {
    int ans = -1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        } else 
            r = mid - 1;
    }
    
    return ans;
}

signed main() {
    fastIO;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    cout << search(0, MAXN);
    return 0;
}