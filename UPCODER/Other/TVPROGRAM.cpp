#include <iostream>
using namespace std;
 
int main() {
    int n; 
    bool check = true;
    cin >> n;

    int arr[n]; 
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n; i++) {
        if (arr[0] > 15) {
            cout << 15; 
            check = false;
            break;

        } else if (arr[i+1] - arr[i] > 15) {
            if (arr[i] + 15 >= 90) cout << 90;
            else cout << arr[i] + 15; 
            check = false;
            break;
        }
    } 

    if (check) cout << (arr[n-1] < 75 ? arr[n-1]+15 : 90);
    return 0;
}