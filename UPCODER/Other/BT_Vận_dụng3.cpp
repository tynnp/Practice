#include <iostream>
using namespace std;
 
int main() {
    int n, k; 
    bool check = true;
    cin >> n >> k;
    int arr[n]; 
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n; i++)
        if (k == arr[i]) {
            cout << i + 1;
            check = false;
            break;
        }

    if (check) cout << -1;
    return 0;
}