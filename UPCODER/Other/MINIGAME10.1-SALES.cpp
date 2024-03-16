#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m, res = 0;
    cin >> n >> m;

    int arr[n];
    for (int &x : arr) cin >> x;
    
    sort(arr, arr + n);
    for (int i = 0; i < m; i++)
        if (arr[i] < 0) res += -arr[i];
    
    cout << res;
    return 0;
}