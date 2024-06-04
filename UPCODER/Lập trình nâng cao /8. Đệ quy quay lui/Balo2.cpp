#include <bits/stdc++.h>
using namespace std;

int n, w, ans(0);
int giaTri(0), khoiLuong(0);
int a[1001], c[1001];
vector<int> ketQua(1001, 0), duongDi(1001, 0);

void Try(int i) {
    if (khoiLuong > w) return; 
    
    if (i > n) { 
        if (giaTri > ans) {
            ans = giaTri;
            ketQua = duongDi;
        }
        return;
    }
    
    Try(i + 1);
    
    duongDi[i] = 1;
    giaTri += c[i];
    khoiLuong += a[i];
    
    Try(i + 1);
    
    duongDi[i] = 0;
    giaTri -= c[i];
    khoiLuong -= a[i];
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> c[i];
        
    Try(1);
    
    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        cout << ketQua[i] << " ";
    return 0;
}
