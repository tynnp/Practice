#include <iostream>
using namespace std;

int main() {
    int n, max = -10e6;
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n; i++) 
        if (arr[i] + i + 1 > max)
            max = arr[i] + i + 1;
    
    cout << max;
    return 0;
}