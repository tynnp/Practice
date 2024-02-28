#include <iostream>
using namespace std;
 
int main() {
    int n, arr[100], k = 0; 
    cin >> n;
    while (n) arr[k++] = n%2, n /= 2;
    for (int i = k - 1; i >= 0; i--) cout << arr[i]; 
    return 0; 
}