#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n];
    for (long long &x : arr) cin >> x;
    for (long long x : arr) cout << x << " ";
    for (int i = n-1; i >= 0; i--) {
        if (i == n-1) cout << endl;
        cout << arr[i] << " ";
    }
    return 0;
}