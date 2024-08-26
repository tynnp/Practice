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
};

int r, m, n;
Pair a[MAXN], b[MAXN];
int sumA[MAXN], sumB[MAXN];

int search(Pair arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].first < x) 
            left = mid + 1;
        else 
            right = mid;
    }

    return left;
}

signed main() {
    fastIO;
    cin >> r >> m >> n;

    for (int i = 0; i < m; i++) 
        cin >> a[i].first;
  
    for (int i = 0; i < m; i++) 
        cin >> a[i].second;
    
    for (int i = 0; i < n; i++) 
        cin >> b[i].first;
    
    for (int i = 0; i < n; i++) 
        cin >> b[i].second;
        
    sort(a, a + m, [] (const Pair &x, const Pair &y) {
        return x.first < y.first;
    });

    sort(b, b + n, [] (const Pair &x, const Pair &y) {
        return x.first < y.first;
    });

    sumA[0] = 0;
    sumB[0] = 0;

    for (int i = 0; i < m; i++) 
        sumA[i + 1] = sumA[i] + a[i].second;
    
    for (int i = 0; i < n; i++) 
        sumB[i + 1] = sumB[i] + b[i].second;
    
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int cntA = search(a, m, a[i].first);
        int sumR = sumA[m] - sumA[cntA];
        
        int cntB = search(b, n, r - a[i].first);
        int sumL = sumB[n] - sumB[cntB];
        
        ans = max(ans, sumR + sumL);
    }
    
    cout << ans;
    return 0;
}
