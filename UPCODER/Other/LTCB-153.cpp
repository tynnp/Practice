#include <iostream>
using namespace std;

int main() {
    int n, min = 10e6; 
    cin >> n; 
    int arr[n];
    for (int &x : arr) cin >> x;
    
    for (int x : arr) 
        if (x < min && x % 2 == 0) min = x;

    cout << (min == 10e6 ? -1 : min);
    return 0;
}