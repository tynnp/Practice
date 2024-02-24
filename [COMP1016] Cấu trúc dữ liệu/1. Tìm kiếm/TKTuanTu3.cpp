#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int k) {
    int res = -10e6;
    
    for (int i = 0; i < n; i++) 
        if (arr[i] > res && arr[i] <= k) 
            res = arr[i];

    for (int i = 0; i < n; i++) 
        if (res != -10e6 && res == arr[i]) 
            return i;

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n = 0, arr[100]; 
    cin >> k;
    while (cin >> arr[n]) n++;
    
    cout << sequentialSearch(arr, n, k);
    return 0;
}