#include <iostream>
using namespace std;
 
int main() {
    int n, k, dem = 0, m = 0; 
    bool check = true;
    cin >> n >> k;
    int arr[n]; 
    for (int &x : arr) cin >> x;

    for (int i = 1; i < n; i++) 
        if (arr[i-1] != arr[i]) m++;

    if (m == 0 && arr[0] == 0) {
        cout << 0; 
        check = false;
    }

    for (int i = 0; i < n; i++) 
        if (arr[i] >= arr[k-1] && arr[i] != 0) dem++;
        
    if (check) cout << dem;
    return 0;
}