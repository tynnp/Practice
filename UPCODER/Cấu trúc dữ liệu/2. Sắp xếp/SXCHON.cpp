#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++)
            if (arr[min] > arr[j]) min = j;
        swap(arr[i], arr[min]);
    }
}

int main() {
    int tmp, n = 0, arr[1001];
    while (cin >> tmp) arr[n++] = tmp;
    
    selectionSort(arr, n);
    
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    return 0;
}