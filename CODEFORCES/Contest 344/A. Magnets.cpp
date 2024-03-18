#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt(0);
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;
    
    for (int i = 0; i < n; i++)
        if (arr[i] != arr[i+1]) cnt++;

    cout << cnt;
    return 0;
}