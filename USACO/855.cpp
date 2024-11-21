#include <iostream>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("mixmilk.in", "r", stdin)
#define out freopen("mixmilk.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 3;
const int MOD = 1e9 + 7;

int n = 3;
int c[MAXN], m[MAXN];

signed main() {
    fastIO; inp; out;

    for (int i = 0; i < MAXN; i++)
        cin >> c[i] >> m[i];

    for (int i = 0; i < 100; i++) {
        int cur = i % MAXN;
        int next = (i + 1) % MAXN;

        // Đảm bảo lượng sữa không quá giới hạn xô next
        int move = min(m[cur], c[next] - m[next]);

        m[cur] -= move;
        m[next] += move;
    }
    
    for (int &x : m)
        cout << x << endl;

    return 0;
}