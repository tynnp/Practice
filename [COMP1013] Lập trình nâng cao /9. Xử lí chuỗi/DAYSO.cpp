#include <iostream>
using namespace std;

int daySo(int n) {
    if (n < 2) return n;
    if (n % 2 == 0) return daySo(n/2);
    else return daySo(n/2) + daySo(n/2 + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int max = -1;
    for (int i = 0; i <= n; i++) 
        if (daySo(i) > max) 
            max = daySo(i);
    cout << max; 
    return 0;
}