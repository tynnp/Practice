#include <iostream>
using namespace std;
 
int main() {
    int n, dem = 0; 
    cin >> n;
    int arr[n], arr2[n]; 

    for (int &x : arr) cin >> x;
    for (int i = 1; i < n-1; i++) 
        if (arr[i-1]*arr[i+1] == arr[i])
            arr2[dem++] = i+1;

    if (dem > 0) {
        cout << dem << endl;
        for (int i = 0; i < dem; i++) 
            cout << arr2[i] << " ";
    } else 
        cout << -1;
        
    return 0;
}