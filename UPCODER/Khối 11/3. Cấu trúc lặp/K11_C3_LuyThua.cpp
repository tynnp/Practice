#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, res = 1; 
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
        res *= n;

    cout << res;
    return 0;
}