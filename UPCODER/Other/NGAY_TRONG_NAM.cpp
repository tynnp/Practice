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

int day, month, year;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weekdays[] = {"Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay"};

signed main() {
    fastIO;
    cin >> day >> month >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        days[2] = 29; 

    int sumDay = 0;
    for (int i = 1; i < month; i++)
        sumDay += days[i];
    sumDay += day; 

    int N = year + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + sumDay - 1;
    cout << weekdays[N % 7];
    return 0;
}
