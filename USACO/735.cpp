#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("lostcow.in", "r", stdin)
#define out freopen("lostcow.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO; inp; out;
    int n, d, x, y;
    cin >> x >> y;

    y -= x;
    d = abs(y);
    
    n = ceil(log(d) / log(2));  // Bước n -> duy chuyển 2^n -> duy chuyển tối đa 2^(n+1) - 1 => 2^(n+1) - 1 >= d tìm n >= log2(d)
    n += (n + (y < 0)) % 2;     // Nếu y < 0 (bên trái) hoặc n lẻ

    cout << 2 * (pow(2, n) - 1) + d;    
    return 0;
}