// #include <bits/stdc++.h>
// using namespace std;

// void radixSortReverse(int arr[], int n) {
//     int mx = arr[0];
//     for (int i = 1; i < n; i++)
//         if (arr[i] > mx) mx = arr[i];
    
//     int exp = 1;
//     while (mx / exp > 0) {
//         vector<int> res(n);
//         int cnt[10] = {0};
        
//         for (int i = 0; i < n; i++) 
//             cnt[(arr[i] / exp) % 10]++;
        
//         for (int i = 8; i >= 0; i--)  
//             cnt[i] += cnt[i + 1];
        
//         for (int i = n-1; i >= 0; i--) {
//             res[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
//             cnt[(arr[i] / exp) % 10]--;
//         }
        
//         for (int i = 0; i < n; i++)
//             arr[i] = res[i];
        
//         exp *= 10;
//     }
// }

// int main() {
//     long long n, k, ans(0);
//     cin >> n >> k;
    
//     int arr[n];
//     for (int &x : arr) cin >> x;
    
//     ans = arr[0], arr[0] = 0;
//     radixSortReverse(arr, n);
//     //for (int x : arr) cout << x << " "; 
    
//     for (int i = 0; i < n; i++) {
//         if (i < k) ans += arr[i];
//         else ans -= arr[i];
//     }
    
//     cout << ans;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long a[n];
    for (long long &x : a) cin >> x;

    long long ans = a[0];
    a[0] = 0;
    
    sort(a, a + n, [] (long long x, long long y) {
        return x > y;
    });

    for (int i = 0; i < n; i++) {
        if (i < k) ans += a[i];
        else ans -= a[i];
    }

    cout << ans;
    return 0;
}