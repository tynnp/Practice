#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int arr[100];
    while (cin >> arr[n]) n++;

    int max = -9999, max2 = -9998, min = 9999, min2 = 9998;
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (max2 < arr[i] && arr[i] < max) max2 = arr[i];
        if (min2 > arr[i] && arr[i] > min) min2 = arr[i];
    }

    cout << max2 - min2;
    return 0;
}