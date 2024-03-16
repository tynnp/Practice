#include <iostream>
using namespace std;

void xuatMang(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n; 
    cin >> n; 
    int arr[n];
    for (int &x : arr) cin >> x;
    xuatMang(arr, n);
    return 0;
}