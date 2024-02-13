#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 
    long long fac = 1;
    while (n > 1) fac *= n--;
    cout << fac;
    return 0;
}