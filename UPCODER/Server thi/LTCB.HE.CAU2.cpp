#include <bits/stdc++.h>
using namespace std;

int main() {
    double x;
    int ans = 0;
    cin >> x;
    
    if (x < 0) cout << "NHAP SAI";
    else {
        x = round(x);
        if (x < 2) ans = 3000 * x;
        else if (x < 11) ans = 3000 + (x - 1) * 2000; 
        else ans = 3000 + 9*2000 + (x - 10) * 1500;
        cout << ans;
    }
    
    return 0;
}