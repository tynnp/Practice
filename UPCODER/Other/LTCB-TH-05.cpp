#include <iostream>
using namespace std;
 
int main() {
    int n; 
    cin >> n;
    int chan = 0, le = 1, arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] > 0) chan += arr[i];
        if (arr[i] % 2 != 0 && arr[i] > 0) le *= arr[i];
    }
    cout << chan << " " << le;
    return 0;
}