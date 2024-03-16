#include <iostream>
using namespace std;

int main() {
    int n, res = 0; 
    cin >> n; 
    int arr[n]; 
    for (int &x : arr) cin >> x;
    for (int x : arr) res += x;
    cout << (res % 2 == 0);
    return 0;
}