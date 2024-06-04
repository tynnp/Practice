#include <bits/stdc++.h>
using namespace std;

int n, w, sum(0), ans(0);
int a[1001];
vector<int> duongDi, ketQua;

void Try(int i) {
    if (sum > w) return;

    if (sum > ans) {
        ans = sum;
        ketQua = duongDi;
    }

    for (int j = i + 1; j <= n; ++j) {
        sum += a[j];
        duongDi.push_back(j - 1);
        
        Try(j);
        
        sum -= a[j];
        duongDi.pop_back();
    }
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) cin >> a[i];
        
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        duongDi.push_back(i-1);
        
        Try(i);
        
        sum -= a[i];
        duongDi.pop_back();
    }
    
    cout << ans << endl;
    for (int x : ketQua) cout << x << " ";
    return 0;
}