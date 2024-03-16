#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size; cin >> size;
    int arr[size];

    for (int &x : arr) cin >> x;

    int k; cin >> k;
    int res = k;

    for (int i = 1; i < size; i++) {
        if (k + arr[i-1] >= arr[i])
            res += (arr[i] - arr[i-1]);
        else 
            res += k;
    }

    cout << res;
    return 0;
}