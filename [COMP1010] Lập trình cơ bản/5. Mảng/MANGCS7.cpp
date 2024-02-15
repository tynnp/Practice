#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;
    for (int x : arr) cout << x << " ";
    return 0;
}