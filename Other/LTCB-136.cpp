#include <iostream>
using namespace std;

int main() {
    int n, res = -1; 
    cin >> n; 
    int arr[n];
    for (int &x : arr) cin >> x;

    for (int x : arr) 
        if (x % 2 == 0) res = x;
        
    cout << res;
    return 0;
}