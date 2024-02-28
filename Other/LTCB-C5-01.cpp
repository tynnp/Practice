#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n; 
    int arr[n], res = 0; 
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) res += arr[i];
    cout << res;
    return 0;
}