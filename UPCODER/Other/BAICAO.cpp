#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int tinhDiem(vector<string> v) {
    int res = 0;
    char jqk = 0;

    for (string c : v) {
        if (c == "J" || c == "Q" || c == "K") {
            jqk++;
            res += 100;
            continue;
        }

        if (c == "A")       
            res += 1;
        else if (c == "10")
            res += 10;
        else 
            res += c[0] - '0';
    }

    if (jqk == 3)
        return res;
    else 
        return res % 10;
}

vector<string> a[5];
string user[] = {"Su", "Lu", "Bu", "Ti", "Teo"};

signed main() {
    fastIO;

    for (int i = 0; i < 5; i++) {
        string x, y, z;
        cin >> x >> y >> z;
        a[i].push_back(x);
        a[i].push_back(y);
        a[i].push_back(z);
    }

    int maxDiem = 0;
    for (int i = 0; i < 5; i++) 
        maxDiem = max(maxDiem, tinhDiem(a[i]));
    
    for (int i = 0; i < 5; i++) 
        if (maxDiem == tinhDiem(a[i]))
            cout << user[i] << ' ';
    
    return 0;
}