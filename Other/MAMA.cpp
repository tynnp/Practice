#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long res = 0, arr[n];
    for (long long &x : arr) cin >> x;

    for (int i = n-1; i >= 0; i--) 
        for (int j = i; j >= 0; j--)
            if (arr[i] < arr[j]) res += arr[j] - arr[i];

    cout << res % 1000000000;
    return 0;
}