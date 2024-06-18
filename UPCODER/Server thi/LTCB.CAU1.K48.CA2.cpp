#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[3];
    bool check = false;
    
    cin >> n;
    for (int &x : arr) cin >> x;
    
    for (int x : arr) {
        if ((int) log10(x) + 1 == n) {   
            cout << x << " ";
            check = true;
        }
    }
    
    if (!check) cout << -1;
    return 0;
}