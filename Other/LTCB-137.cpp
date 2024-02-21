#include <iostream>
using namespace std;

int main() {
    int n, index = -1; 
    cin >> n; 
    double min = 10e6, arr[n];

    for (double &x : arr) cin >> x;
    
    for (int i = 0; i < n; i++)
        if (min > arr[i]) min = arr[i], index = i;
        
    cout << index;
    return 0;
}