#include <iostream>
#include <cmath>
using namespace std;

bool check(int arr[], int n) {
    for (int i = 1; i < n; i++) 
        if (arr[i-1] != arr[i]) 
            return false;
    return true;
}

int main() {
    int n, tmp, cnt = 0;
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;

    while (!check(arr, n)) {
        cnt++;
        tmp = arr[0];

        for (int i = 0; i < n; i++) {
            if (i != n-1) arr[i] = abs(arr[i] - arr[i+1]);
            else arr[i] = abs(arr[i] - tmp);
        }

        if (cnt == 1000) break;
    }

    if (cnt == 1000) cout << "Impossible";
    else cout << cnt;
    return 0; 
}