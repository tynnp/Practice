#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("shuffle.in", "r", stdin)
#define out freopen("shuffle.out", "w", stdout)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 100 + 5;

int n, idx[MAXN], cows[MAXN], temp[MAXN];

signed main() {
    fastIO; inp; out;
    cin >> n;

    for (int i = 1; i <= n; i++) 
        cin >> idx[i];

    for (int i = 1; i <= n; i++) 
        cin >> cows[i];

    for (int step = 0; step < 3; step++) {
        for (int i = 1; i <= n; i++) 
            temp[i] = cows[idx[i]];
            
        for (int i = 1; i <= n; i++)
            cows[i] = temp[i];
    }

    for (int i = 1; i <= n; i++) 
        cout << cows[i] << endl;

    return 0;
}
