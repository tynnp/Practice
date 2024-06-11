#include <bits/stdc++.h>
using namespace std;

int n, x[20];

void print() {
    for (int i = 0; i < n; i++)
        cout << x[i];
    cout << '\n';
}

void Try(int k) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (k == n-1) print();
        else Try(k + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    Try(0);
    return 0;
}