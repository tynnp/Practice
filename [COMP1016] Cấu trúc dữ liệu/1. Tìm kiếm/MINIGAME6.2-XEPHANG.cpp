#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 1, max = 0; 
    cin >> n; 
    int arr[n];
    for (int& x : arr) cin >> x;
    vector<int> vt;

    for (int i = 1; i < n; i++) {
        if (arr[i-1] == arr[i]) cnt++;
        if (arr[i-1] != arr[i] || i == n-1) 
            vt.push_back(cnt), cnt = 1;
    }

    for (int x : vt) if (max < x) max = x;
    cout << n - max;
    
    return 0;
}