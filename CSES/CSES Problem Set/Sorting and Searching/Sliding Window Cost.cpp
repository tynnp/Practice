#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define elif else if 
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k;
int a[MAXN];
multiset<int> low, up;
int sLow, sUp;

void Insert(int x) {
    int m = *low.rbegin();
    if (m < x) {
        up.insert(x);
        sUp += x;
        if (up.size() > k/2) {
            int tmp = *up.begin();
            low.insert(tmp);
            up.erase(up.find(tmp));
            sLow += tmp;
            sUp -= tmp;
        }
    } else {
        low.insert(x);
        sLow += x;
        if (low.size() > (k+1)/2) {
            int tmp = *low.rbegin();
            up.insert(tmp);
            sUp += tmp;
            sLow -= tmp;
            low.erase(low.find(tmp));
        }
    }
}

void Erase(int x) {
    if (up.find(x) != up.end()) {
        up.erase(up.find(x));
        sUp -= x;
    } else {
        low.erase(low.find(x));
        sLow -= x;
    }

    if (low.empty()) {
        int m = *up.begin();
        low.insert(m);
        up.erase(m);
        sLow += m;
        sUp -= m;
    }
}

signed main() {
    fastIO;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    low.insert(a[0]);
    sLow += a[0];

    for (int i = 1; i < k; i++) 
        Insert(a[i]);

    cout << sUp - sLow + (k % 2 == 0 ? 0 : *low.rbegin()) << ' ';
    
    for (int i = k; i < n; i++) {
        if (k == 1) {
            Insert(a[i]);
            Erase(a[i - k]);
        } else {
            Erase(a[i - k]);
            Insert(a[i]);
        }

        cout << sUp - sLow + (k % 2 == 0 ? 0 : *low.rbegin()) << ' ';
    }
     
    return 0;
}  