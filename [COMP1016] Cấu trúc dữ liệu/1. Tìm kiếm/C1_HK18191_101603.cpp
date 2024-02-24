#include <iostream>
using namespace std;
 
int main() {
    int n, x, k = -1, max = -10e6; 
    cin >> n >> x;
    int arr[n]; 
    bool check = true;

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int i = 0; i < n; i++) 
        if (arr[i] == x) {
            cout << "Y\n" << i; 
            check = false;
            break;
        }

    for (int i = 0; i < n; i++) 
        if (arr[i] < x && arr[i] >= max) 
            max = arr[i], k = i;

    if (check) {
        cout << "N\n";
        cout << (k != -1 ? k : -1);
    }

    return 0;
}