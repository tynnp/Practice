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

int n, m;
vector<int> v;

int check(int mid) {
    int sum = 0;
    o
    for (int i = 0; i < n; i++) {
        sum += mid / v[i];
        if (sum >= m)
            break;
    }
    
    return sum;
}

int search(int l, int r) {
    if (l > r) 
        return l;
    
    int mid = (l + r) / 2;
    if (check(mid) >= m)
        return search(l, mid-1);
    else 
        return search(mid+1, r);
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    cout << search(0, 1e18);
}

signed main() {
    fastIO;
    solve();
    return 0;
}