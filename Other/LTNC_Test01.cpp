#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, m, tmp, cnt = 0;
    cin >> n >> m;

    bool *arr = new bool[1000];
    memset(arr, false, sizeof(arr));

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp] = true;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (!arr[tmp]) {
            cnt += 1;
            arr[tmp] = true;
        }
    }

    cout << cnt;
    return 0;
}