#include <iostream>
using namespace std;

int main() {
    int n, min = 10e6; 
    cin >> n; 
    int arr[n]; 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (min > arr[i]) min = arr[i];
    }

    int min_2 = 10e6;
    for (int i = 0; i < n; i++) 
        if (min_2 > arr[i] && arr[i] > min)
            min_2 = arr[i];

    cout << (min_2 == 10e6 ? "NO" : to_string(min_2));
    return 0;
}