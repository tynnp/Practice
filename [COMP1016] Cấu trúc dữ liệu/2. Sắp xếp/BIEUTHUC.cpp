#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k; 
    long long res, sum = 0;
    cin >> n >> k;

    int arr[n];
    for (int &x : arr) cin >> x;
    res = arr[0];

    for (int i = 1; i < n; i++) 
        sum += arr[i];
    res -= sum;

    sort(arr+1, arr+n, greater<int>());

    for (int i = 0; i < k; i++) 
        res += 2*arr[i+1];
        
    cout << res;
    return 0;
}