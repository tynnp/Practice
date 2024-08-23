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

string s;

set<string> solve(string s) {
    set<string> res;
    sort(s.begin(), s.end());
    
    do {
        res.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    
    return res;
}

signed main() {
    fastIO;
    cin >> s;
    set<string> res = solve(s);
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << endl;
    return 0;
}