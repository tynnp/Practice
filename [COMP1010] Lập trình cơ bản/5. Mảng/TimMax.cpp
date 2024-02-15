#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int arr[100], n = 0;
    int tmp, max = -10e6;
    
    while (cin >> tmp) {
        arr[n++] = tmp;
        if (tmp > max) max = tmp;
    }

    cout << max; 
    return 0;
}