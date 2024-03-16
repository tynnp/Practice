#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n; 
    cin >> n;
    double arr[n];
    for (auto &x : arr) cin >> x;

    double max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    cout << fixed << setprecision(2) << (max + min)/2.0;
    return 0;
}