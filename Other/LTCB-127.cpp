#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n; 
    float arr[n];
    for (float &x : arr) cin >> x;

    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[j-1] >= arr[j]) 
            swap(arr[j-1], arr[j]), j--;
    }
    
    for (float x : arr) cout << x << " ";
    return 0;
}