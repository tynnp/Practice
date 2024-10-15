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

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int a, b;
bool prime[MAXN];

signed main() {
    fastIO;
    cin >> a >> b;
    fill(prime, prime + MAXN, true);

    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= MAXN; i++) 
        if (prime[i])
            for (int j = i*i; j < MAXN; j += i)
                prime[j] = false;

    for (int i = a; i <= b; i++)
        if (prime[i])
            cout << i << endl;
    
    return 0;
}