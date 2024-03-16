#include <iostream>
using namespace std;


int main() {
    int n; 
    cin >> n; 

    int arr[n]; 
    for (int& x : arr) cin >> x;

    int max = 9999;
    for (int x : arr) if (max > x) max = x;

    int max2 = 9999;
    for (int x : arr) if (max2 > x && x > max) max2 = x;

    cout << (max2 != 9999 ? to_string(max2) : "NO");
    return 0;
} 