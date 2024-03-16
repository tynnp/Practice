#include <iostream>
#include <cmath>
#include <algorithm>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int a = abs(arr[0]) + abs(arr[1]);
    int b = abs(arr[n-1]) + abs(arr[n-2]);
    cout << (a < b ? b : a);

    return 0;
}