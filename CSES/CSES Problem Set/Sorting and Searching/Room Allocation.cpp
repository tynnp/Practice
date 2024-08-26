#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Pair {
    int first;
    int second;
    int index;
    Pair() {};
    Pair(int a, int b): first(a), second(b) {};
};

bool operator < (const Pair &x, const Pair &y) {
    return x.first < y.first;
}

int n;
multiset<Pair> s;
int pos[MAXN];
Pair v[MAXN];

signed main() {
    fastIO;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].index = i;
    }
        
    sort(v, v + n, [] (Pair x, Pair y) {
        if (x.first == y.first)
            return x.second < y.second;
        return x.first < y.first;
    });
    
    // for (int i = 0; i < n; i++) {
    //     cout << v[i].first << " " << v[i].second << " " << v[i].index << " ";
    //     cout << endl;
    // }
    
    s.insert(Pair(v[0].second, s.size()+1));
    pos[v[0].index] = 1;
    
    for (int i = 1; i < n; i++) {
        auto it = s.lower_bound(Pair(v[i].first, INT_MAX));
        
        if (it == s.begin())
        {
            pos[v[i].index] = s.size()+1;
            s.insert(Pair(v[i].second, s.size()+1));
        }
        else {
            --it;
            pos[v[i].index] = it->second;
            s.erase(it);
            s.insert(Pair(v[i].second, pos[v[i].index]));
           
        }
    }
    
    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
        cout << pos[i] << " ";
    return 0;
}



// 4
// 4 3 2 2 1 1 1 1 1 1 



