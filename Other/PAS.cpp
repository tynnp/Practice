#include <iostream>
using namespace std;


int main() {
    int n, k; 
    cin >> n;
    int arr[n];

    for (int &x : arr) cin >> x;
    cin >> k;

    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j] >= arr[j-1]) 
            swap(arr[j], arr[j-1]), j--; 
    }

    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;

    if (k > arr[0]) cout << k << " ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        if (arr[i] > k && k > arr[i+1]) 
            cout << k << " ";
    }
    if (arr[n-1] > k) cout << k;

    return 0;
}