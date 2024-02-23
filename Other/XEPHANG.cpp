#include <iostream>
using namespace std;

int main() {
    int n; 
    cin >> n;
    int k, vi_tri, arr[n]; 
    cin >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            vi_tri = i; 
            break;
        }
    } 

    cout << vi_tri + 1 << endl;
    for (int i = 0; i < vi_tri; i++) 
        cout << arr[i] << " ";
    
    cout << k << " ";
    for (int i = vi_tri; i < n; i++) 
        cout << arr[i] << " ";

    return 0;
}