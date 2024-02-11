#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int a = abs(arr[0]) + abs(arr[1]);
    int b = abs(arr[n-1]) + abs(arr[n-2]);
    cout << (a < b ? b : a);

    return 0;
}