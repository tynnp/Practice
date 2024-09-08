#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Range {
    int left, right, index;
};

struct Pair {
    int first, second;
};

bool operator < (const Pair &x, const Pair &y) {
    if (x.first != y.first)
        return x.first < y.first;
    return x.second > y.second;
}

#define indexed_set tree<Pair, null_type, less<Pair>, rb_tree_tag, tree_order_statistics_node_update>

int n, k = 1;
Range a[MAXN];
int pos1[MAXN], pos2[MAXN];

signed main() {
    fastIO;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].left >> a[i].right;
        a[i].index = i;
    }
    
    sort(a, a + n, [] (Range x, Range y) {
        if (x.left == y.left) 
            return x.right > y.right;
        return x.left < y.left;
    });
    
    // pos 1
    indexed_set s;
    
    for (int i = n-1; i >= 0; i--) {
        pos1[a[i].index] = s.order_of_key({a[i].right, LLONG_MIN});
        s.insert({a[i].right, k++});
    }
    
    // pos 2
    s.clear();
    for (int i = 0; i < n; i++) {
        pos2[a[i].index]= s.size() - s.order_of_key({a[i].right, LLONG_MAX});
        s.insert({a[i].right, k++});
    }
    
    for (int i = 0; i < n; i++)
        cout << pos1[i] << " ";
    cout << endl;
    
    for (int i = 0; i < n; i++)
        cout << pos2[i] << " ";
        
    return 0;
}