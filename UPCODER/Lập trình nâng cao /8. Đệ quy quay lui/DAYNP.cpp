#include <bits/stdc++.h>
using namespace std;

int n;
int res[100];

void print() {
    for (int i = 1; i <= n; i++)
        cout << res[i];
    cout << endl;
}

void Try(int x) {
    for (int i = 0; i <= 1; i++) {
        res[x] = i;
        if (x == n) print();
        else Try(x + 1);
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}