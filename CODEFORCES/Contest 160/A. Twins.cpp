#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum(0);
    cin >> n;
    
    int arr[n];
    for (int &x : arr) {
        cin >> x;
        sum += x;
    }

    sum = sum/2;
    sort(arr, arr + n);

    int cnt(0), res(0);
    for (int i = n-1; i >= 0; i--) {
        res += arr[i];
        cnt++;
        if (res > sum) break;
    }

    cout << cnt;
    return 0;
}