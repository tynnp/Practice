#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    double arr[n], min = 10e6;
    for (double &x : arr) cin >> x;

    for (double x : arr) 
        if (min > x) min = x;
        
    cout << min;
    return 0;
}