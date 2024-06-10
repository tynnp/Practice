#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    int left = 0, right = n-1;
    
    while (left <= right) {
        int mid = (left + right)/2;
        if (arr[mid] < k) left = mid + 1;
        else if (arr[mid] > k) right = mid - 1;
        else return mid;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        bool check = false;
        cin >> n >> k;
        
        int arr[n];
        for (int &x : arr) cin >> x;
        
        for (int i = 0; i < n; i++) {
            if (k-arr[i] > 0)
                if (binarySearch(arr, n, k-arr[i]) != -1 &&
                (arr[i] % 2 == 0 && (k-arr[i]) % 2 != 0) || 
                (arr[i] % 2 != 0 && (k-arr[i]) % 2 == 0)) {
                    check = true;
                    break;
                }
        }
        
        cout << check;
    }
    
    return 0;
} 