#include <iostream>
using namespace std;

void xuatMang(double arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n; 
    cin >> n; 
    double arr[n];
    for (double &x : arr) cin >> x;
    xuatMang(arr, n);
    return 0;
}