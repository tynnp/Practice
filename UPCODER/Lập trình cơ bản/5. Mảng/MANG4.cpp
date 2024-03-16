#include <iostream>
using namespace std;

bool nguyenTo(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int arr[n];
    for (int &x : arr) cin >> x;

    int sum = 0;
    for (int x : arr)
        if (nguyenTo(x)) sum += x;
    
    cout << sum;
    return 0;
}