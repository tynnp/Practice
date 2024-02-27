#include <iostream>
using namespace std;

int main() {
    int n, tmp;
    cin >> n;

    int arr[n+1];
    fill(arr, arr + n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp]++;
    }

    for (int i = 0; i <= n; i++)
        if (arr[i] == 0) cout << i << " ";
        
    return 0;
}