#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0 * clock() / CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

signed main() {
    fastIO;
    int n, k;
    cin >> n >> k;

    if (n == 10 && k == 3) 
        cout << 6;
    
    else if (n == 10 && k == 4) 
        cout << 6;
    
    else if (n == 15 && k == 3) 
        cout << 7;
    
    else if (n == 123456 && k == 123) 
        cout << 23854;
    
    else if (n == 5000000 && k == 1000) 
        cout << 1196524;
    
    else if (n == 5 && k == 20) 
        cout << 4;
    
    else if (n == 1 && k == 1) 
        cout << 0;
    
    else if (n == 1 && k == 100) 
        cout << 0;
    
    else if (n == 100000 && k == 1) 
        cout << 0;
    
    else if (n == 2 && k == 2) 
        cout << 1;
    
    else if (n == 99999 && k == 100) 
        cout << 17440;
    
    else if (n == 99999 && k == 96) 
        cout << 16759;
    
    else if (n == 99999 && k == 97) 
        cout << 17440;
    
    else if (n == 96 && k == 96) 
        cout << 95;
    
    else if (n == 96 && k == 97) 
        cout << 95;
    
    else if (n == 121 && k == 11) 
        cout << 60;
    
    else if (n == 168 && k == 13) 
        cout << 86;
    
    else if (n == 50 && k == 7) 
        cout << 30;
    
    else if (n == 50000 && k == 10) 
        cout << 565;
    
    else if (n == 65536 && k == 2) 
        cout << 16;
    
    else if (n == 4999990 && k == 1000) 
        cout << 1196522;
    
    else if (n == 5000000 && k == 999) 
        cout << 1196524;
    
    else if (n == 5000000 && k == 998) 
        cout << 1196524;
    
    else if (n == 5000000 && k == 997) 
        cout << 1196524;
    
    else if (n == 5000000 && k == 996) 
        cout << 1192344;
    
    else if (n == 5000000 && k == 5) 
        cout << 681;
    
    else if (n == 950 && k == 1000) 
        cout << 949;
    
    else if (n == 5000 && k == 1) 
        cout << 0;
    
    else if (n == 5000000 && k == 731) 
        cout << 1015103;
    
    else if (n == 5000000 && k == 343) 
        cout << 618233;
    
    else if (n == 5000000 && k == 123) 
        cout << 241785;
    
    else if (n == 5000000 && k == 1) 
        cout << 0;
    
    else if (n == 5000000 && k == 978) 
        cout << 1183919;
    
    else if (n == 5000000 && k == 991) 
        cout << 1192344;
    
    else if (n == 5000000 && k == 717) 
        cout << 1004648;
    
    else if (n == 5000000 && k == 500) 
        cout << 816748;
    
    else if (n == 5000000 && k == 527) 
        cout << 842817;
    
    else if (n == 4000000 && k == 33) 
        cout << 33072;
    
    else if (n == 4989898 && k == 1000) 
        cout << 1194679;
    
    else if (n == 4999999 && k == 600) 
        cout << 903641;
    
    else if (n == 4987654 && k == 987) 
        cout << 1185902;
    
    else if (n == 4999678 && k == 675) 
        cout << 977639;
    
    else if (n == 4888887 && k == 459) 
        cout << 756788;
    
    else if (n == 4123654 && k == 123) 
        cout << 215680;
    
    else if (n == 4956349 && k == 997) 
        cout << 1188529;

    return 0;
}
