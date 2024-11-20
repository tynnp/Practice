#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("promote.in", "r", stdin)
#define out freopen("promote.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int arr[9];
    int bronze, silver, gold;

    for (int i = 1; i <= 8; i++)
        cin >> arr[i];

    gold = arr[8] - arr[7];
    silver = arr[6] - arr[5] + gold;
    bronze = arr[4] - arr[3] + silver;

    cout << bronze << endl << silver << endl << gold;
    return 0;
}