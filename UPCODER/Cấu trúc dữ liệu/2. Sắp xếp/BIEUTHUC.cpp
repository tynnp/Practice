#include <iostream>
using namespace std;

void quickSort(long long a[], long long left, long long right) {
    if (left >= right) 
        return;

    long long x = a[(left + right) / 2];
    long long i = left, j = right;

    while (i <= j) {
        while (a[i] > x) i++;
        while (a[j] < x) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main() {
    long long n, k;
    cin >> n >> k;

    long long a[n];
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    long long ans = a[0];
    a[0] = 0;

    quickSort(a, 0, n-1);

    for (int i = 0; i < n; i++) {
        if (i < k) ans += a[i];
        else ans -= a[i];
    }

    cout << ans;
    return 0;
}