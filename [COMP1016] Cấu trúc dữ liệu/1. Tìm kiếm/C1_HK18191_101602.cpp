#include <iostream>
using namespace std;
 
int main() {
    int n, x, k = -1; 
    cin >> n >> x;
    int arr[n]; 
    bool check = true;

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int i = 0; i < n; i++) 
        if (arr[i] == x) k = i;

    if (k != -1) {
        cout << "Y\n" << k; 
        check = false;
    } 

    for (int i = 0; i < n; i++) 
        if (arr[i] > x && check) {
            cout << "N\n" << i; 
            check = false;
            break;
        }

    if (check) cout << "N\n" << -1;
    return 0;
}