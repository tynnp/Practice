#include <bits/stdc++.h>
using namespace std;

int n, k, cnt(0);
int giaTri[100];

void print() {
    cnt += 1;
    for (int i = 1; i <= k; i++)
        cout << giaTri[i] << " ";
    cout << endl;
}

void Try(int x) {
    for (int i = giaTri[x-1] + 1; i <= n - k + x; i++) {    
        giaTri[x] = i;
        if (x == k) print();
        else Try(x + 1);
    }
}

int main() {
    cin >> n >> k;
    Try(1);
    cout << cnt;
    return 0;
}