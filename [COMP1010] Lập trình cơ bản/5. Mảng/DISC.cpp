
// Chưa đúng

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, size = 0; 
    cin >> n >> k;

    bool check[n + 1];
    int res[k];
    memset(check, true, sizeof(check));

    check[0] = false;
    for (int i = 0; i < k; i++) {
        int tmp; cin >> tmp;
        check[tmp] = false;
        res[size++] = tmp;
    }
    
    for (int i = size-1; i >= 0; i--)
        cout << res[i] << " ";

    for (int i = 0; i <= n; i++)
        if (check[i]) cout << i << " ";

    return 0;
}