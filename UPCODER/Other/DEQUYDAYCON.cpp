#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define inp freopen("file.inp", "r", stdin)
#define out freopen("file.out", "w", stdout)
#define TIME 1.0*clock()/CLOCKS_PER_SEC
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 20;
const int MOD = 1e9 + 7;

int n, k, sum;
bool check;
int arr[MAXN];
vector<int> res;

void Try(int i) {
    if (sum >= k || i == n) {
        if (sum == k) {
            for (int x : res) 
                cout << x << " ";
            cout << endl;
            check = true;
        } 
        return;
    }
    
    for (int j = i + 1; j <= n; j++) {
        sum += arr[j];
        res.push_back(arr[j]);
        Try(j);
        sum -= arr[j];
        res.pop_back();
    }
}

signed main() {
    fastIO;
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    
    for (int i = 1; i <= n; i++) {
        sum = arr[i]; 
        res.clear();
        res.push_back(arr[i]);
        Try(i);
    }
    
    if (!check) cout << -1;
    return 0;
}