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

const int MAXN = 1e7 + 5;
const int MOD = 1e9 + 7;

int a, b;
bool prime[MAXN];

signed main() {
    fastIO;
    cin >> a >> b;
    fill(prime, prime + MAXN, true);

    prime[0] = prime[1] = false;
    for (int i = 2; i*i < MAXN; i++)
        if (prime[i])
            for (int j = i*i; j < MAXN; j += i)
                prime[j] = false;
    
    int ans = 0;
    for (int i = a; i <= b; i++)
        ans += prime[i];

    cout << ans;
    return 0;
}