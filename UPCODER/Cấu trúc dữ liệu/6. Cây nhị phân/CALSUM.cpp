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

int n, m, ans;
int arr[MAXN];
int Tree[4 * MAXN];

void init(int k, int left, int right) {
    if (left == right) {
        Tree[k] = arr[left];
        return;
    }
    
    int mid = (left + right)/2;
    init(2*k, left, mid);
    init(2*k + 1, mid + 1, right);
    Tree[k] = Tree[2*k] + Tree[2*k + 1];
}

void solve(int k, int left, int right, int a, int b) {
    if (right < a || left > b) return;
  
    if (a <= left && right <= b) {
        ans += Tree[k];
        return;
    }
    
    int mid = (left + right)/2;
    solve(2*k, left, mid, a, b);
    solve(2*k + 1, mid + 1, right, a, b);
}

signed main() {
    fastIO;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, 1, n);
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        ans = 0;
        solve(1, 1, n, a, b);
        cout << ans << endl;
    }
    
    return 0;
} 