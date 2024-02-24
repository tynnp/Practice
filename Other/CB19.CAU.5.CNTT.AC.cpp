#include <iostream>
using namespace std;

int main() {
    int min = 99999, max = -99999, indexMax = -1, indexMin = -1;
    int arr[100], n = 0;
    while (cin >> arr[n]) n++;

    for (int i = 0; i < n; i++) {
        if (min > arr[i]) min = arr[i], indexMin = i;
        if (max < arr[i]) max = arr[i], indexMax = i;
    }

    cout << indexMax + indexMin;
    return 0;
}