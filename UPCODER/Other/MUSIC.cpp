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
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int n, k, ans;
int a[MAXN];
deque<int> minDQ, maxDQ;

signed main() {
    fastIO;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int left = 1, right = 1;
    ans = LLONG_MAX;

    while (right <= n) {
        while (!maxDQ.empty() && a[maxDQ.back()] <= a[right])
            maxDQ.pop_back();
        maxDQ.push_back(right);

        while (!minDQ.empty() && a[minDQ.back()] >= a[right])
            minDQ.pop_back();
        minDQ.push_back(right);

        while (!maxDQ.empty() && !minDQ.empty() && a[maxDQ.front()] - a[minDQ.front()] >= k) {
            ans = min(ans, right - left + 1);

            if (!maxDQ.empty() && maxDQ.front() == left)
                maxDQ.pop_front();

            if (!minDQ.empty() && minDQ.front() == left)
                minDQ.pop_front();

            left++;
        }

        right++;
    }

    cout << (ans == LLONG_MAX ? -1 : ans);
    return 0;
}