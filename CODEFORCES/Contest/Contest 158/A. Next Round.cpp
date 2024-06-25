#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt = 0;
    cin >> n >> k;

    int arr[n];
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n; i++)
        cnt += (arr[i] >= arr[k-1] && arr[i] > 0);

    cout << cnt;
    return 0;
}