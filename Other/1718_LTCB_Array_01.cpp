#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    if (n == 0) cout << "NULL";
    else {
        for (int &x : arr) cin >> x;
        for (int i = n-1; i >= 0; i--) {
            cout << arr[i];
            if (i != 0) cout << " ";
        }
    }

    return 0;
}