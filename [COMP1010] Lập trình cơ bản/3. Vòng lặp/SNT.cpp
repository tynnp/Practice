#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, cnt = 0; cin >> n;
    for (int i = 2; i*i <= n; i++)
        cnt += (n % i == 0);
    cout << (cnt == 0 ? "true" : "false");
    return 0;
}