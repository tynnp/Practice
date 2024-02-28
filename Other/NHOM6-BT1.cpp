#include <iostream>
using namespace std;
 
int main() {
    int n, k; 
    bool check = true;
    cin >> n >> k;

    int arr[n]; 
    for (int &x : arr) cin >> x;

    int mid, L = 0, R = n-1;
    while(L <= R) {
        mid = (L+R)/2;
        if (arr[mid] == k) {
            cout << mid; 
            check = false;
            break;
            
        } else { 
            if (arr[mid] < k) L = mid+1;
            else R = mid-1;
        }
    }

    if (check) cout << -1;
    return 0;
}