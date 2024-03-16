#include <iostream>
using namespace std;

int main() {
    int n, index = -1, min = -1; 
    cin >> n; 
    int arr[n];
    for (int& x : arr) cin >> x;

    for (int i = 0; i < n; i++)
        if (arr[i] < min) min = arr[i], index = i;
        
    cout << index;
    return 0;
}