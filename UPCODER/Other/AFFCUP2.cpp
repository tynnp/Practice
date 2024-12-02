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

struct ThongTin {
    string doiNha, doiKhach;
    int diemNha, diemKhach;
} a, b, c, d;

char kt;
int tongDiem[5];

signed main() {
    fastIO;
    cin >> a.doiNha >> a.diemNha >> kt >> b.diemKhach >> b.doiKhach;
    cin >> b.doiNha >> b.diemNha >> kt >> a.diemKhach >> a.doiKhach;
    cin >> c.doiNha >> c.diemNha >> kt >> d.diemKhach >> d.doiKhach;
    cin >> d.doiNha >> d.diemNha >> kt >> c.diemKhach >> c.doiKhach; 
    
    tongDiem[1] = a.diemNha + a.diemKhach;
    tongDiem[2] = b.diemNha + b.diemKhach;
    tongDiem[3] = c.diemNha + c.diemKhach;
    tongDiem[4] = d.diemNha + d.diemKhach;

    if (tongDiem[1] > tongDiem[2])
        cout << a.doiNha;
    else if (tongDiem[1] < tongDiem[2])
        cout << b.doiNha;
    else {
        if (a.diemKhach > b.diemKhach)
            cout << a.doiNha;
        else 
            cout << b.doiNha;
    }

    cout << " - ";

    if (tongDiem[3] > tongDiem[4])
        cout << c.doiNha;
    else if (tongDiem[3] < tongDiem[4])
        cout << d.doiNha;
    else {
        if (c.diemKhach > d.diemKhach) 
            cout << c.doiNha;
        else 
            cout << d.doiNha;
    }

    return 0;
}