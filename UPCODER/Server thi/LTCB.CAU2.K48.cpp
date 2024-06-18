#include <bits/stdc++.h>
using namespace std;

bool cp(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    int n;
    bool check = false;
    
    cin >> n;
    for (int i = 0; i <= n; i++)
        if (cp(i)) {
            cout << i << " "; 
            check = true;
        }
    
    if (!check) cout << -1;
    return 0;
}