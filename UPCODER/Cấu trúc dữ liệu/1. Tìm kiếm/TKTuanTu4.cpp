#include <bits/stdc++.h>
using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    int res = -1, val = INT_MIN;
    for (int i = 0; i < n; i++)
        if (arr[i] > val && arr[i] <= x)
            res = i, val = arr[i];
    return res;
}

int main() {
    int x, n = 0;
    int tmp, arr[1001];
    
    cin >> x;
    while (cin >> tmp)
        arr[n++] = tmp;
        
    int ans = sequentialSearch(arr, n, x);
    if (ans != -1) {
        for (int i = 0; i <= ans; i++)
            if (arr[i] == arr[ans])
                cout << i << " ";
    } else cout << ans;
    
    return 0;
}