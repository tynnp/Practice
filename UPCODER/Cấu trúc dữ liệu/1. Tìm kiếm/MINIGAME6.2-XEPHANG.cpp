#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, maxVal = INT_MIN; 
    cin >> n; 
    
    int arr[n], val[n] = {1};
    for (int& x : arr) cin >> x;
    
    for (int i = 1; i < n; i++) 
        if (arr[i-1] == arr[i]) val[i] = val[i-1] + 1;
        else val[i] = 1;

    for (int x : val) 
        if (maxVal < x) maxVal = x;
    cout << n - maxVal;
    return 0;
}