#include <iostream>
using namespace std;

bool nt(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    int n, index = -1;
    cin >> n;

    int arr[n];
    for (int &x : arr) cin >> x;

    for (int i = 0; i < n; i++) {
        if (nt(arr[i])) index = i;
        for (int j = 0; j < n; j++) {
            if (arr[index] > arr[j] && nt(arr[j]))
                swap(arr[index], arr[j]);
        }
    }

    for (int x : arr) cout << x << " ";
    return 0;
}