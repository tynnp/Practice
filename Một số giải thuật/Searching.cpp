#include <iostream>
using namespace std;

// Tìm kiếm tuần tự 
int sequentialSearch(int arr[], int n, int k) {
    for (int i = 0; i < n; i++)
        if (arr[i] == k) return i;
    return -1;
}

// Tìm kiếm nhị phân
int binarySearch(int arr[], int n, int k) {
    int mid;
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == k) return mid;
        if (arr[mid] < k) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {

    return 0;
}