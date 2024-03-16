#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    int arr[n], cnt = 0;
    for (int &x : arr) cin >> x;

    for (int x : arr) {
        if (x % 2 == 0) {
            cnt++;
            cout << x; 
            break;
        }
    }

    if (cnt == 0) cout << -1;
    return 0;
}