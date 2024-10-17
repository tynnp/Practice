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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, m, ans = INT_MAX;
bool prime[MAXN];
int matrix[505][505];
int update[505][505];
vector<int> primeNumber;

signed main() {
    fastIO;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    fill(prime, prime + MAXN, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= MAXN; i++) {
        if (prime[i])   
            for (int j = i*i; j < MAXN; j += i)
                prime[j] = false;
    }

    for (int i = 2; i < MAXN; i++) 
        if (prime[i])   
            primeNumber.push_back(i);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto it = lower_bound(primeNumber.begin(), primeNumber.end(), matrix[i][j]);
            update[i][j] += *it - matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++)
            sum += update[i][j];
        ans = min(ans, sum);
    }

    for (int j = 0; j < m; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += update[i][j];
        ans = min(ans, sum);
    }
    
    cout << ans;
    return 0;
}