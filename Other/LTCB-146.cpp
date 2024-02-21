#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    double arr[n];
    for (double &x : arr) cin >> x;

    for (double x : arr) {
        if (x < 0) {
            cout << x;
            return 0;
        }
    } 
    
    cout << 1;
    return 0;
}