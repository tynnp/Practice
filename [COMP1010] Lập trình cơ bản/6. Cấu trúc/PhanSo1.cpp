#include <iostream>
#include <algorithm>
using namespace std;

struct PhanSo {
    int tu, mau;
} a, b, res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a.tu >> a.mau;
    cin >> b.tu >> b.mau;

    if (a.mau == 0 || b.mau == 0) cout << -1;
    else {
        res.tu = a.tu*b.mau + b.tu*a.mau;
        res.mau = a.mau * b.mau;
        int ucln = __gcd(res.tu, res.mau);
        res.tu /= ucln;
        res.mau /= ucln;
        cout << res.tu << "/" << res.mau;
    }
    
    return 0;
}