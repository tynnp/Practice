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

struct Range {
    int left, right, index;
};

int n;
Range a[MAXN];
int pos1[MAXN], pos2[MAXN];

// trả về true nếu y chứa x
bool check(Range x, Range y) {
    return x.left >= y.left && x.right <= y.right;
}

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
    set<int> s;
    for (int i = n-1; i >= 0; i--) {
        auto it = s.upper_bound(a[i].right);
        if (it != s.begin())
            pos1[a[i].index]++;
        s.insert(a[i].right);
    }
    
    // pos 2
    s.clear();
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(a[i].right);
        if (it != s.end())
            pos2[a[i].index]++;
        s.insert(a[i].right);
    }
    
    for (int i = 0; i < n; i++)
        cout << (pos1[i] > 0) << " ";
    cout << endl;
    
    for (int i = 0; i < n; i++)
        cout << (pos2[i] > 0) << " ";
        
    return 0;
}