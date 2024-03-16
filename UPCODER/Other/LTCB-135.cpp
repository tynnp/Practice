#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    double arr[n];
    bool check = true;
    for (double &x : arr) cin >> x;

    for (double x : arr) 
        if (x > 0) {
            cout << x; 
            check = false;
            break;
        } 
    
    if (check) cout << -1;
    return 0;
}