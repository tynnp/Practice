#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n = 0, arr[1000];
    cin >> x;
    while (cin >> arr[n]) n++;

    int res = -10e6;
    for (int i = 0; i < n; i++)
        if (arr[i] > res && arr[i] <= x)    
            res = arr[i];

    for (int i = 0; i < n; i++)
        if (res == arr[i]) 
            cout << i << " ";
    
    if (res == -10e6) cout << -1;
    return 0;
}