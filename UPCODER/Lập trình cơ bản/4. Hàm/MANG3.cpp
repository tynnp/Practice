#include <iostream>
#include <cmath>
using namespace std;

bool chinhPhuong(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;

    int sum = 0;
    for (int x : arr) 
        if (chinhPhuong(x)) sum += x;

    cout << sum;
    return 0;
}