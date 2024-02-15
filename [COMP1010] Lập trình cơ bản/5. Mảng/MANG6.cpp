#include <iostream>
#include <cmath>
using namespace std;

bool nguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

bool chinhPhuong(int n) {
    return (int) sqrt(n) == sqrt(n);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;

    for (int x : arr) 
        if (chinhPhuong(x)) cout << x << " "; cout << endl;
    
    for (int x : arr) 
        if (nguyenTo(x)) cout << x << " "; 

    return 0;
}