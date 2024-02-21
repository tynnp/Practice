#include <iostream>
using namespace std;

void lietKe(int arr[], int n) {
    bool check = false;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
            check = true;
        }
    }

    if (!check) cout << -1;
 }

int main() {
    int n; 
    cin >> n;    
    int arr[n]; 
    for (int& x : arr) cin >> x;
    lietKe(arr, n);
    return 0;
}