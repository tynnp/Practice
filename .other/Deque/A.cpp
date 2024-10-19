/*
Cho một dãy A gồm N phần tử được đánh số từ 1 đến N. Phần tử thứ i có giá trị là A[i].
Cho k là một số nguyên dương (k <= N). Với mỗi phần tử i (k <= i <= N), tìm giá trị nhỏ nhất của các phần tử trong đoạn i-k+1 đến i trong dãy A.
minRange[i] = giá trị nhỏ nhất trong đoạn [i-k+1 .. i]
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)
#define indexed_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, k, a[MAXN];
deque<int> dq;

signed main() {
    fastIO;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);

        if (dq.front() + k <= i)
            dq.pop_front();

        if (i >= k)
            cout << a[dq.front()] << endl;
    }
    
    return 0;
}