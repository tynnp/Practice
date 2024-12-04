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

const int MAXN = 50 + 5;
const int MOD = 1e9 + 7;

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int n, m, t;
char c[MAXN][MAXN];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool find(string &word, int x, int y, int dir, vector<pair<int, int>> &kq) {
    int len = word.size();
    kq.clear();

    for (int i = 0; i < len; i++) {
        if (!isValid(x, y) || c[x][y] != word[i])
            return false;

        kq.emplace_back(x + 1, y + 1);
        x += dx[dir];
        y += dy[dir];
    }

    return true;
}

bool search(string &word, vector<pair<int, int>> &kq) {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            for (int dir = 0; dir < 8; dir++)
                if (find(word, i, j, dir, kq))
                    return true;
    return false;
}

signed main() {
    fastIO;
    cin >> n >> m >> t;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];

    while (t--) {
        string word;
        cin >> word;
        vector<pair<int, int>> kq;

        if (search(word, kq)) {
            cout << "YES" << endl;
            for (auto &p : kq) 
                cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;

        } else  
            cout << "NO" << endl;
    }

    return 0;
}