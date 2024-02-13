#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, i = 1; 
    cin >> n;

    while (n > 0) 
        n -= i, i += 1;

    cout << (n == 0 ? "YES" : "NO");
}