#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) 
            if (arr[min] > arr[j]) min = j;
        swap(arr[min], arr[i]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[100], n = 0;
    while (cin >> arr[n]) n++;

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}