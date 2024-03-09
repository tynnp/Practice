#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[n], res = 0;
    for (int &x : arr) cin >> x;

    sort(arr, arr + n);
    for (int i = 0; i < k; i++) 
        res += arr[i];

    cout << res;
    return 0;
}