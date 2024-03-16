#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n], min = 10e6;
    for (double &x : arr) cin >> x;

    for (double x : arr) 
        if (x < min && x > 0) min = x;
        
    cout << (min == 10e6 ? -1 : min);
    return 0;
}